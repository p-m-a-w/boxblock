#include "chain.hpp"
#include "block.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include <cstdint>

bool starterDataCheck(const string filename) {
    struct stat Buff = {};
    return stat(filename.c_str(), &Buff) == 0; // Check ว่ามี File อยู่ไหม, return true มี / false ไม่มี 
}

void createChainFile(const string filename, const vector<block> &chain) {
    deleteChain(filename);
    ofstream source;
    source.open(filename);
    for(const auto &a: chain)source <<  a << endl;
    source.close();
}

void addBlockToChain(block current, vector<block> &chain) {
    block *x = chain.size() ? &chain.back() : NULL;
    chain.push_back(current);
    if (x) chain.back().link(*x);
}

void importChain(const string filename, vector<block> &chain) {
    chain.clear();
    ifstream s(filename);
    block empty, data;
    for (s >> data; !memcmp(&empty, &data, sizeof(block)); s >> data) {
        block *x = chain.size() ? &chain.back() : NULL;
        chain.push_back(data);
        if (x) chain.back().link(*x);
    }
}

bool hashCheck(const vector<block> &chain) {
    return (chain.size()) ? block::validation(&chain.back()) : true; // because empty always valid
}

void deleteChain(const string filename) {
    // include cstdio แล้วใช้ฟังก์ชั่น remove ก็ได้นะ
    remove(filename.c_str());
}

