//
// Created by 86183 on 2023/1/5.
//

#include "DictionaryTree.h"
#include <string>

DictionaryTree::DictionaryTree() {
    root = new TrieNode();
}

auto DictionaryTree::search(std::string word) -> bool {
    TrieNode *node = root;
    for (auto c: word) {
        if (node->children[c - 'a'] == NULL) {
            return false;
        }
        node = node->children[c - 'a'];
    }
    return node->isEnd;
}
