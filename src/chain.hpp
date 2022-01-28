#ifndef _CHAIN_HPP
#define _CHAIN_HPP
#include <vector>
#include <string>
#include "block.hpp"

using namespace std;

bool starterDataCheck(const string filename); //
void createChainFile(const string filename, const vector<block> &chain); // เปลี่ยนเชนออกเป็นไฟล์ aka export
// block createBlock(int); // สร้างบล๊อกใช้ฟังก์ชั่นทดแทน
void addBlockToChain(block, vector<block> &chain); // เชื่อมเป็นลูกโซ่
void importChain(const string filename, vector<block> &chain); // เอาเชนจากไฟล์มาให้ได้
bool hashCheck(const vector<block> &chain); //เช็คว่าchainไม่ถูกแก้ สมเหตุสมผล
void deleteChain(const string filename);
#endif
