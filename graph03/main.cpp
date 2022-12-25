#include <iostream>
#include <vector>
#include <queue>


void BFS(std::vector<std::vector<int>> &graph) {

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[0].size(); j++) {
            if (graph[i][j] == 1) {
                std::vector<std::vector<bool>> visited(graph.size(), std::vector<bool>(graph[0].size(), false));
                std::queue<std::pair<int, int>> q;
                q.push({i, j});
                int cnt = 0;
                while (!q.empty() && cnt != 4) {
                    auto [x, y] = q.front();
                    q.pop();
                    visited[x][y] = true;
                    cnt++;
                    if (x + 1 < graph.size() && graph[x + 1][y] == 1 && !visited[x + 1][y]) {
                        q.push({x + 1, y});
                    }
                    if (x - 1 >= 0 && graph[x - 1][y] == 1 && !visited[x - 1][y]) {
                        q.push({x - 1, y});
                    }
                    if (y + 1 < graph[0].size() && graph[x][y + 1] == 1 && !visited[x][y + 1]) {
                        q.push({x, y + 1});
                    }
                    if (y - 1 >= 0 && graph[x][y - 1] == 1 && !visited[x][y - 1]) {
                        q.push({x, y - 1});
                    }
                }

                q.push({i, j});
                if (cnt >= 4) {
                    //擦去所有的1
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        graph[x][y] = 0;
                        q.pop();
                        cnt++;
                        if (x + 1 < graph.size() && graph[x + 1][y] == 1) {
                            q.push({x + 1, y});
                        }
                        if (x - 1 >= 0 && graph[x - 1][y] == 1) {
                            q.push({x - 1, y});
                        }
                        if (y + 1 < graph[0].size() && graph[x][y + 1] == 1) {
                            q.push({x, y + 1});
                        }
                        if (y - 1 >= 0 && graph[x][y - 1] == 1) {
                            q.push({x, y - 1});
                        }
                    }
                }
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> graph{{1, 1, 0, 0, 1},
                                        {1, 0, 0, 1, 1},
                                        {1, 1, 0, 1, 0},
                                        {0, 0, 1, 0, 0},
                                        {0, 1, 1, 0, 0}};

    BFS(graph);

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[0].size(); j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
