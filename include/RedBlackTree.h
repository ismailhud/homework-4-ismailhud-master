#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>
#include <vector>
#include "Entry.h"
#include "Node.h"

class RedBlackTree {
public:
    std::vector<Entry> get(std::string searchable_name);
    void put(std::string searchable_name, Entry entry);
    int* count_red_and_black_edges();

private:
    Node* root = nullptr;
};

#endif //REDBLACKTREE_H
