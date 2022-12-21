#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::unordered_map<char, std::vector<char>> graph;


void create_graph() {
    graph['A'] = {'D'};
    graph['B'] = {'A', 'C'};
    graph['C'] = {'A'};
}

std::unordered_map<char, std::vector<char>> create_pregraph() {
    std::vector<bool> visited(graph.size(), false);
    std::unordered_map<char, std::vector<char>> res;

    for (auto it = graph.begin(); it != graph.end(); it++) {
        res[it->first].emplace_back(NULL);
        if (visited[it->first]) {
            continue;
        }
        std::queue<char> q;
        q.push(it->first);
        visited[it->first] = true;
        while (!q.empty()) {
            char node = q.front();
            q.pop();

            for (auto item: graph[node]) {
                res[item].push_back(node);
                if (visited[item]) {
                    continue;
                }

                q.push(item);
                visited[item] = true;
            }
        }
    }
    return res;
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


bool judge(std::unordered_map<char, std::vector<char>> graph_2) {
    std::unordered_map<char, std::vector<char>> graph_1 = graph;
    for (auto it = graph_2.begin(); it != graph_2.end(); it++) {
        //找到入度为0的节点
        if (it->second.size() == 1) {
            //擦除该节点以及他的出度
            graph_1.erase(it->first);
            for (auto it2 = graph_2.begin(); it2 != graph_2.end(); it2++) {
                if (graph_2[it2->first].) {

                }
            }
        }
    }

    return graph_1.size();
}

int main() {
    create_graph();
    std::vector<bool> visited_1(graph.size(), false);
    BFS(visited_1);
    std::cout << "---------------------------" << std::endl;
    std::vector<bool> visited_2(graph.size(), false);
    DFS(visited_2);

    std::unordered_map<char, std::vector<char>> res = create_pregraph();

    std::cout << judge(res) << std::endl;
    return 0;
}
