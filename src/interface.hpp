#pragma once
#include "block.hpp"
#include <vector>

void submitVote(int); // submit -> chain
std::vector<block> loadRecentChain(int);
