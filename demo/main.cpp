#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void f(vector<int> &a) {
    if (!a.empty()) {
        a.pop_back();
    }
}

int main() {
    unordered_map<int, vector<int>> map;
    map[1].resize(100);
    map[1][2] = 3;
    vector<int> s;
    s.resize(100);
    s[2] = 3;
    for (auto it: map[1]) {
        cout << it << endl;
    }
    return 0;
}
