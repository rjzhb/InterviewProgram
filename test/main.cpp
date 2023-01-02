#include <iostream>
#include <unordered_map>

struct Node {
    int val;
};
int main() {
    std::unordered_map<int, void *> map;
    Node node;
    node.val = 1;
    map[1] = reinterpret_cast<void *> (&node);
    std::cout << map[1] << std::endl;
    return 0;
}
