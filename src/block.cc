#include "block.hpp"
#include <memory>

void hash_fn(char data[], char &output, size_t size) {
    char hash = 0;
    for (int i = 0; i < size; ++i) {
        hash ^= data[i];
    }
    output = hash;
}

void hash(block &b) {
    char t[HASH_SIZE + DATA_SIZE] = {}, hash = 0;
    memcpy(t, b.depend, HASH_SIZE);
    memcpy(t + HASH_SIZE, b.data, DATA_SIZE);
    hash_fn(t, hash, HASH_SIZE + DATA_SIZE);
    memcpy(b.hash, &hash, HASH_SIZE);
}

void link(block &current, block &prev) {
    current.prev = &prev;
    prev.next = &current;
    memcpy(current.depend, prev.hash, HASH_SIZE);
    hash(current);
}

bool validation(const block *b) {
    char t[HASH_SIZE + DATA_SIZE] = {}, hash = 0;
    memcpy(t, b->depend, HASH_SIZE);
    memcpy(t + HASH_SIZE, b->data, DATA_SIZE);
    hash_fn(t, hash, HASH_SIZE + DATA_SIZE);

    bool result = !memcmp(&hash, b->hash, HASH_SIZE);
    if (b->prev == NULL) return result;
    else if (!result) return result;
    else return result && validation(b->prev);
}
