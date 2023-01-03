//
// Created by 86183 on 2023/1/3.
//

#include "Trie.h"

void Trie::insert(std::string word) {
    TrieNode *node = root;
    for (auto c: word) {
        if (node->children[c - 'a'] == NULL) {
            node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
    }
    node->isEnd = true;
}

bool Trie::search(std::string word) {
    TrieNode *node = root;
    for (auto c: word) {
        if (node->children[c - 'a'] == NULL) {
            return false;
        }
        node = node->children[c - 'a'];
    }
    return node->isEnd;
}

bool Trie::starts_with(std::string prefix) {
    TrieNode *node = root;
    for (auto c: prefix) {
        if (node->children[c - 'a'] == NULL) {
            return false;
        }
        node = node->children[c - 'a'];
    }
    return true;
}

Trie::Trie() {
    root = new TrieNode();
}
