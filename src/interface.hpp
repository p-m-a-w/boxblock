#pragma once
#include "block.hpp"

void submitVote(int choice, vector<block> &chain); // submit -> chain
std::vector<block> loadRecentChain(int n ,const vector<block> &chain);
std::vector<int> summary(const vector<block> &chain); // Summary of voting in chain.
