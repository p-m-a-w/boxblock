#pragma once
#include "block.hpp"

void submitVote(int choice, std::vector<block> &chain); // submit -> chain
std::vector<int> countVote(const std::vector<block> &chain); // Summary of voting in chain.
