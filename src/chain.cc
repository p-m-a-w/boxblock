#include "chain.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

bool starterDataCheck(const string filename) {
    struct stat Buff = {};
    return stat(filename.c_str(), &Buff) == 0; // Check ว่ามี File อยู่ไหม
}

void createChainFile(const string filename, const vector<block> &chain) {
    // แนะนำให้ใช้ ofstream สร้างไฟล์เอา
    // ละอาจจะใช้ for(const block &b : chain) o_stream << b << "\n";

}

void addBlockToChain(block, vector<block> &chain) {
    // link แล้ว hash แล้ว push_back เลยครับ
}

void importChain(const string filename, vector<block> &chain) {
    // แนะนำให้ใช้ ifstream แล้ว getline แต่ละบรรทัด
    // โดยใช้ฟังก์ชั่น getline(ifstream, block&); โดยให้ link ก่อนแล้วค่อย push_back
}

bool hashCheck(const vector<block> &chain) {
    // ใช้ validation บนตัวสุดท้ายของเชน
}

void deleteChain(const string filename) {
    // include cstdio แล้วใช้ฟังก์ชั่น remove ก็ได้นะ
}