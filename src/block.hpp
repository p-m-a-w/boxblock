#ifndef _BLOCK_HPP
#define _BLOCK_HPP
#include <cstddef>
#include <vector>
#include <fstream>

const size_t HASH_SIZE = 1;
const size_t DATA_SIZE = 32;

class block {
        char depend[HASH_SIZE] = {}, c_hash[HASH_SIZE] = {};
    protected:
        block *prev = NULL, *next = NULL;
    public:
        char data[DATA_SIZE] = {};
        block();
        block(const char *);
        void hash();
        void link(block &);
        static bool validation(const block *);

        friend std::ifstream& operator>>(std::ifstream &, block &);
        friend std::ofstream& operator<<(std::ofstream &, const block &);
};

void getline(std::ifstream&, block&);
std::ifstream& operator>>(std::ifstream &, const block &);
std::ofstream& operator<<(std::ofstream &, const block &);
#endif