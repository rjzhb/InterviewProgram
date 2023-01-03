//
// Created by 86183 on 2023/1/3.
//

#ifndef T9ENTER_TRIE_H
#define T9ENTER_TRIE_H


#include <string>

class Trie {
public:

    Trie();

    ~Trie() = default;

    void insert(std::string word);

    bool search(std::string word);

    bool starts_with(std::string prefix);

private:
    struct TrieNode {
        bool isEnd;
        TrieNode *children[26];

        TrieNode() {
            isEnd = false;
        }
    };

    TrieNode *root;
};


#endif //T9ENTER_TRIE_H
