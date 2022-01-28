#include "block.hpp"
#include <iostream>
#include <fstream>

int main(int argc, const char* argv[]) {
    bool in = true;
    block a;
    if (in) {
        std::ifstream s("test.txt");
        s >> a;
    } else {
        std::ofstream s("test.txt");
        a = block("333");
        s << a;
    }

    std::cout << a.data << " ";
    std::cout << block::validation(&a);
    return 0;
}
