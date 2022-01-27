#ifndef _CHAIN_HPP
#define _CHAIN_HPP
#include <vector>
#include <string>
#include "block.hpp"

using namespace std;

void starterDataCheck(string filename); //
void createChainFile(string filename); //
block createBlock(int); //
void addBlockToChain(block, vector<block> &chain); // เชื่อมเป็นลูกโซ่
void importchain(string filename, vector<block> &chain);
bool hashCheck(vector<block> &chain); //เช็คว่าchainไม่ถูกแก้ สมเหตุสมผล
void deletedChain(string filename);
#endif
