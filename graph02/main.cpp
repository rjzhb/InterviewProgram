#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::unordered_map<char, std::vector<char>> graph;


void create_graph() {
    graph['A'] = {'B', 'D'};
    graph['B'] = {'C'};
    graph['C'] = {'A'};
}

std::unordered_map<char, int> create_indegree() {
    std::unordered_map<char, int> indegree_map;
    std::vector<bool> visited(graph.size(), false);

    for (auto it = graph.begin(); it != graph.end(); it++) {
        if (indegree_map.find(it->first) == indegree_map.end()) {
            indegree_map[it->first] = 0;
        }

        for (auto item: it->second) {
            indegree_map[item]++;
        }
    }
    return indegree_map;
}


void BFS(std::vector<bool> &visited) {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        if (visited[it->first]) {
            continue;
        }

        std::queue<char> q;
        q.push(it->first);
        visited[it->first] = true;
        std::cout << it->first << std::endl;
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            for (auto item: graph[node]) {
                if (visited[item]) {
                    continue;
                }

                q.push(item);
                visited[item] = true;
                std::cout << item << std::endl;
            }
        }
    }
}


void DFS(char node, std::vector<bool> &visited) {
    for (auto it: graph[node]) {
        if (visited[it]) {
            continue;
        }
        std::cout << it << std::endl;
        visited[it] = true;
        DFS(it, visited);
    }
}

void DFS(std::vector<bool> &visited) {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        auto key = it->first;
        auto val = it->second;
        if (visited[key]) {
            continue;
        }
        std::cout << key << std::endl;
        visited[key] = true;
        DFS(key, visited);
    }
}

//判断图是否有环，有环返回false，无环返回true
bool judge(std::unordered_map<char, int> indegree_map) {
    int cnt = graph.size();
    std::queue<char> q;

    for (auto it: indegree_map) {
        if (it.second == 0) {
            q.push(it.first);
        }
    }
    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cnt--;
        for (auto it: graph[node]) {
            if (--indegree_map[it] == 0) {
                q.push(it);
            }
        }
    }

    return cnt == 0;
}


int main() {
    create_graph();
    std::vector<bool> visited_1(graph.size(), false);
    BFS(visited_1);
    std::cout << "---------------------------" << std::endl;
    std::vector<bool> visited_2(graph.size(), false);
    DFS(visited_2);

    std::unordered_map<char, int> indegree_map = create_indegree();

    std::cout << judge(indegree_map) << std::endl;
    return 0;
}
