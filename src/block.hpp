#ifndef _BLOCK_HPP
#define _BLOCK_HPP
#include <cstddef>

#define HASH_SIZE 1
#define DATA_SIZE 32

typedef struct _block {
    char depend[HASH_SIZE] = {};
    char data[DATA_SIZE] = {};
    char hash[HASH_SIZE] = {};
    const _block *prev = NULL;
    const _block *next = NULL;
} block;

block a = {
    .data = itoa(a)
};

void hash(block &);
void link(block &, block &);
bool validation(const block *);
#endif