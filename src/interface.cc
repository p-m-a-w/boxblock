#include "interface.hpp"

vector<block> loadRecentChain(int n ,const vector<block> &chain){
    vector<block> recent;
    for (unsigned int i = chain.size()-1; i >= chain.size()-n; i--)
        recent.push_back(chain[i]);
    return recent;
}