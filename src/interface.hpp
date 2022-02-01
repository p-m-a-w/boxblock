#pragma once
#include "block.hpp"
#include <vector>

void submitVote(int); // submit -> chain
void resetChain();
std::vector<block> loadRecentChain(int);
