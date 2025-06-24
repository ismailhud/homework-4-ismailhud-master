#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Entry.h"

struct Node {
    std::string key;
    std::vector<Entry> values;

    Node* left = nullptr;
    Node* right = nullptr;
    bool color = true; // true = RED, false = BLACK

    Node(std::string key, Entry entry)
        : key(std::move(key)), values{entry} {}
};

#endif // NODE_H
