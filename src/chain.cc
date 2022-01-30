#include "chain.hpp"
#include "block.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdint>

bool starterDataCheck(const string filename) {
    struct stat Buff = {};
    return stat(filename.c_str(), &Buff) == 0; // Check ว่ามี File อยู่ไหม, return true มี / false ไม่มี 
}

void createChainFile(const string filename, vector<block> &chain) {
    // แนะนำให้ใช้ ofstream สร้างไฟล์เอา
    // ละอาจจะใช้ for(const block &b : chain) o_stream << b << "\n";
    ofstream source;
    source.open(filename);
    for(block &a : chain) source << a << endl;
}

void addBlockToChain(block current, vector<block> &chain) {
    // link แล้ว hash แล้ว push_back เลยครับ
    current.link(chain.back());
    chain.push_back(current);
}

void importChain(const string filename, vector<block> &chain) {
    // แนะนำให้ใช้ ifstream แล้ว getline แต่ละบรรทัด
    // โดยใช้ฟังก์ชั่น getline(ifstream, block&); โดยให้ link ก่อนแล้วค่อย push_back
    block PresentBlock;
    ifstream Newfile(filename);
    getline(Newfile,PresentBlock);
    if(chain.size()==0){
        chain.push_back(PresentBlock);
    }else{
        PresentBlock.link(chain.back());
        chain.push_back(PresentBlock);
    }
}

bool hashCheck(const vector<block> &chain) {
    // ใช้ validation บนตัวสุดท้ายของเชน
    return block :: validation(&chain.back());
}

void deleteChain(const string filename) {
    // include cstdio แล้วใช้ฟังก์ชั่น remove ก็ได้นะ
    remove(filename.c_str());
}