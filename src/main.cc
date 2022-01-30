#include "chain.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {
    
    string filename = "test.txt";
    if(starterDataCheck(filename)){
        return 32;
    }// ลอง function StarterDataCheck


    return 0;
}
