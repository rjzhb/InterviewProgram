//
// Created by 86183 on 2023/1/5.
//

#ifndef SEARCHTREE_DICTIONARYTREE_H
#define SEARCHTREE_DICTIONARYTREE_H


#include <string>

class DictionaryTree {
public:

    DictionaryTree();

    auto search(std::string word) -> bool;

private:

    struct TrieNode {
        TrieNode *children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
        }
    };

    TrieNode *root;
};


#endif //SEARCHTREE_DICTIONARYTREE_H
