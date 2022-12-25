#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <queue>

//定义无穷远点
static constexpr int INFINITE = 10e6;

//重写set红黑树排序
struct node_compare {
    bool operator()(std::pair<char, int> node_1, std::pair<char, int> node_2) {
        return node_1.second == node_2.second ? node_1.first < node_2.first : node_1.second < node_2.second;
    }
};

std::pair<std::vector<std::pair<char, int>>, std::unordered_map<char, char>>
find_by_dijkstra(std::unordered_map<char, std::unordered_map<char, int>> graph, char source_node) {
    std::set<std::pair<char, int>, node_compare> dist;
    std::vector<std::pair<char, int>> res;

    //记录节点前驱
    std::unordered_map<char, char> node_map;
    //初始状态，先把源点加入集合res,并初始化dist
    res.push_back({source_node, 0});
    node_map[source_node] = source_node;
    //更新整个dist
    for (auto it: graph) {
        if (it.first == res.back().first) {
            continue;
        }
        node_map[it.first] = source_node;
        //-1代表无穷远点
        if (graph[res.back().first][it.first] == INFINITE) {
            dist.insert({it.first, INFINITE});
        } else {
            dist.insert({it.first, graph[res.back().first][it.first] + res.back().second});
        }
    }

    while (!dist.empty()) {
        //将dist最小的节点赋值给临时节点
        res.push_back({dist.begin()->first, dist.begin()->second});
        dist.erase(dist.begin());
        //以临时节点为基础更新整个dist
        for (auto it: dist) {
            if (graph[res.back().first][it.first] != INFINITE) {
                //更新前驱节点
                if (graph[res.back().first][it.first] + res.back().second <= it.second) {
                    node_map[it.first] = res.back().first;
                }

                dist.erase(it);
                dist.insert({it.first, std::min(graph[res.back().first][it.first] + res.back().second, it.second)});
            }
        }
    }

    return {res, node_map};
}

void print_shortest_path(char source_node, char target_node, std::unordered_map<char, char> node_prev) {
    //输出source到target最短路径
    std::queue<char> q;
    q.push(target_node);
    while (!q.empty()) {
        char node = q.front();
        q.pop();
        std::cout << node << "<-";
        if (node_prev[node] != source_node) {
            q.push(node_prev[node]);
        } else {
            std::cout << node_prev[node] << std::endl;
        }
    }
}

int main() {
    std::unordered_map<char, std::unordered_map<char, int>> graph{
            {
                    'A', {
                                 {'A', INFINITE}, {'B', 50},       {'C', 10},       {'D', INFINITE}, {'E', 45},       {'F', INFINITE}
                         }
            },
            {
                    'B', {
                                 {'A', INFINITE}, {'B', INFINITE}, {'C', 15},       {'D', INFINITE}, {'E', 10},       {'F', INFINITE}
                         }
            },
            {
                    'C', {
                                 {'A', 20},       {'B', INFINITE}, {'C', INFINITE}, {'D', 15},       {'E', INFINITE}, {'F', INFINITE}
                         }
            },
            {
                    'D', {
                                 {'A', INFINITE}, {'B', 20},       {'C', INFINITE}, {'D', INFINITE}, {'E', 35},       {'F', 3}
                         }
            },
            {
                    'E', {
                                 {'A', INFINITE}, {'B', INFINITE}, {'C', INFINITE}, {'D', 30},       {'E', INFINITE}, {'F', INFINITE}
                         }
            },
            {
                    'F', {
                                 {'A', INFINITE}, {'B', INFINITE}, {'C', INFINITE}, {'D', INFINITE}, {'E', INFINITE}, {'F', INFINITE}
                         }
            }
    };

    char source_node = 'A';
    auto [res, node_prev] = find_by_dijkstra(graph, source_node);

    for (auto it: res) {
        std::cout << "源点" << source_node << "到" << it.first << "最短距离为:" << it.second << "，最短路径为：";
        print_shortest_path(source_node, it.first, node_prev);
    }

    return 0;
}
