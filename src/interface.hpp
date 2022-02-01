#pragma once
#include "block.hpp"

void submitVote(int); // submit -> chain
std::vector<block> loadRecentChain(int n ,const vector<block> &chain);
