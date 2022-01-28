#include <cstring>
#include "block.hpp"
#include <memory>

void hash_fn(char data[], char &output, size_t size) {
    char hash = 0;
    for (int i = 0; i < size; ++i) {
        hash ^= data[i];
    }
    output = hash;
}

block::block() {
    this->hash();
}

block::block(const char *x) {
    strcpy(this->data, x);
    this->hash();
}

void block::hash() {
    char t[HASH_SIZE + DATA_SIZE] = {}, hash = 0;
    memcpy(t, this->depend, HASH_SIZE);
    memcpy(t + HASH_SIZE, this->data, DATA_SIZE);
    hash_fn(t, hash, HASH_SIZE + DATA_SIZE);
    memcpy(this->c_hash, &hash, HASH_SIZE);
}

void block::link(block &prev) {
    this->prev = &prev;
    prev.next = this;
    memcpy(this->depend, prev.c_hash, HASH_SIZE);
}

bool block::validation(const block *b) {
    char t[HASH_SIZE + DATA_SIZE] = {}, hash = 0;
    memcpy(t, b->depend, HASH_SIZE);
    memcpy(t + HASH_SIZE, b->data, DATA_SIZE);
    hash_fn(t, hash, HASH_SIZE + DATA_SIZE);

    bool result = !memcmp(&hash, b->c_hash, HASH_SIZE);
    if (b->prev == NULL) return result;
    else if (!result) return result;
    else return result && validation(b->prev);
}

std::ifstream& operator>>(std::ifstream &in, block &b) {
    for (int i = 0; i < HASH_SIZE; ++i) b.c_hash[i] = in.get();
    for (int i = 0; i < DATA_SIZE; ++i) b.data[i] = in.get();
    return in;
}

std::ofstream& operator<<(std::ofstream &out, block &b) {
    for (int i = 0; i < HASH_SIZE; ++i) out.put(b.c_hash[i]);
    for (int i = 0; i < DATA_SIZE; ++i) out.put(b.data[i]);
    return out;
}