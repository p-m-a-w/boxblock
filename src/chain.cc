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
    ofstream source;
    deleteChain(filename);
    source.open(filename);
    for(const auto &a: chain) {
        source << a << endl;
    }
    source.close();
}

inline void chain_push_back(block current, vector<block> &chain, bool hash = false) {
    chain.push_back(current);
    if (chain.size() > 1) chain.end()[-1].link(chain.end()[-2]);
    if (hash) chain.back().hash();
}

void addBlockToChain(block current, vector<block> &chain) {
    chain_push_back(current, chain, true);
}

void importChain(const string filename, vector<block> &chain, bool clear) {
    ifstream input(filename);
    block c_data;
    if (clear) chain.clear();
    while (getline(input, c_data)) chain_push_back(c_data, chain);
    input.close();
}

bool hashCheck(const vector<block> &chain) {
    return (chain.size()) ? block::validation(&chain.back()) : true; // because empty always valid
}

void deleteChain(const string filename) {
    remove(filename.c_str());
}

