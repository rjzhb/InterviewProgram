#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Graph{
    map<char, int> indegreeMap; //节点和入度的映射
    map<char, char> nodeTable; //节点连接矩阵
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
