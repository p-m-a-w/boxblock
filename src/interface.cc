#include "interface.hpp"
#include "chain.hpp"

void submitVote(int choice, vector<block> &chain){
    char data[DATA_SIZE] = {};
    data[0] = '0' + choice;
    block vote(data);
    addBlockToChain(vote, chain);
}

vector<block> loadRecentChain(int n ,const vector<block> &chain){
    vector<block> recent;
    for (unsigned int i = chain.size()-1; i >= chain.size()-n; i--)
        recent.push_back(chain[i]);
    return recent;
}
