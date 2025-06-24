#include "../include/RedBlackTree.h"
#include <iostream>

#define RED true
#define BLACK false

namespace {
    bool isRed(Node* x) {
        if (x == nullptr) return false;
        return x->color == RED;
    }

    Node* rotateLeft(Node* h) {
        Node* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    Node* rotateRight(Node* h) {
        Node* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    void flipColors(Node* h) {
        h->color = RED;
        if (h->left) h->left->color = BLACK;
        if (h->right) h->right->color = BLACK;
    }

    void countEdges(Node* node, int& red, int& black) {
        if (!node) return;
        if (node->left) {
            node->left->color == RED ? ++red : ++black;
            countEdges(node->left, red, black);
        }
        if (node->right) {
            node->right->color == RED ? ++red : ++black;
            countEdges(node->right, red, black);
        }
    }

    void getPathColorCount(Node* node, const std::string& key, int& red, int& black) {
        while (node != nullptr) {
            if (key < node->key) {
                if (node->left) node->left->color == RED ? ++red : ++black;
                node = node->left;
            } else if (key > node->key) {
                if (node->right) node->right->color == RED ? ++red : ++black;
                node = node->right;
            } else {
                break;
            }
        }
    }

    Node* insert(Node* h, std::string key, const Entry& entry) {
        if (h == nullptr)
            return new Node(key, entry);

        if (key < h->key)
            h->left = insert(h->left, key, entry);
        else if (key > h->key)
            h->right = insert(h->right, key, entry);
        else
            h->values.push_back(entry);

        if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
        if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
        if (isRed(h->left) && isRed(h->right)) flipColors(h);

        return h;
    }
}

std::vector<Entry> RedBlackTree::get(std::string searchable_name) {
    Node* node = root;
    int red = 0, black = 0;
    getPathColorCount(node, searchable_name, red, black);

    while (node != nullptr) {
        if (searchable_name < node->key)
            node = node->left;
        else if (searchable_name > node->key)
            node = node->right;
        else {
            std::cout << "Red edges on the path: " << red << std::endl;
            std::cout << "Black edges on the path: " << black << std::endl;
            return node->values;
        }
    }
    std::cout << "Red edges on the path: " << red << std::endl;
    std::cout << "Black edges on the path: " << black << std::endl;
    return {};
}

void RedBlackTree::put(std::string searchable_name, Entry entry) {
    root = insert(root, searchable_name, entry);
    root->color = BLACK;
}

int* RedBlackTree::count_red_and_black_edges() {
    int* result = new int[2]{0, 0};
    countEdges(root, result[1], result[0]);
    return result;
}