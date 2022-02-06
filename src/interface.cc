#include "interface.hpp"
#include "chain.hpp"

void submitVote(int choice, vector<block> &chain){
    char data[DATA_SIZE] = {};
    data[0] = '0' + choice;
    addBlockToChain(block(data), chain);
    createChainFile(FILENAME, chain);
}

vector<int> countVote(const vector<block> &chain){
    vector<int> totalSum = {0,0,0,0,0};
    for(const block &b : chain){
        totalSum[atoi(b.data)]++;
    }
    return totalSum;
}
