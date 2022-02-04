#pragma once
#include "block.hpp"

void submitVote(int choice, std::vector<block> &chain); // submit -> chain
std::vector<block> loadRecentChain(int n ,const std::vector<block> &chain);
std::vector<int> summary(const std::vector<block> &chain); // Summary of voting in chain.
