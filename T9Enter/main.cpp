#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Trie.h"

using namespace std;

vector<string> getValidT9Words(string num, vector<string> &words) {
    unordered_map<char, int> map{
            {'!', 1},
            {'@', 1},
            {'#', 1},
            {'a', 2},
            {'b', 2},
            {'c', 2},
            {'d', 3},
            {'e', 3},
            {'f', 3},
            {'g', 4},
            {'h', 4},
            {'i', 4},
            {'j', 5},
            {'k', 5},
            {'l', 5},
            {'m', 6},
            {'n', 6},
            {'o', 6},
            {'p', 7},
            {'q', 7},
            {'r', 7},
            {'s', 7},
            {'t', 8},
            {'u', 8},
            {'v', 8},
            {'w', 9},
            {'x', 9},
            {'y', 9},
            {'z', 9}
    };

    vector<string> res;
    for (int i = 0; i < words.size(); i++) {
        string temp;
        for(auto c: words[i]){
            temp.append(std::to_string(map[c]));
        }
        if(temp == num){
            res.push_back(words[i]);
        }
    }

    return res;
}

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;
    return 0;
}
