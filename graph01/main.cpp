#include <iostream>

#include <vector>
#include <queue>

using namespace std;

bool visited[4] = {0};

void dfs(vector<vector<int>> graph, vector<int> node_list) {
    //输出i
    for (int i = 0; i < node_list.size(); i++) {
        if (visited[node_list[i]])continue;
        cout << node_list[i] << endl;
        visited[node_list[i]] = true;
        //跳转至graph[i]
        dfs(graph, graph[node_list[i]]);
    }

}

void bfs(vector<vector<int>> graph) {
    queue<int> q;
    q.push(0);
    cout << 0 << endl;
    visited[0] = true;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for (auto it: graph[temp]) {
            if (visited[it]) continue;
            q.push(it);
            cout << it << endl;
            visited[it] = true;
        }
    }
}

int main() {
    vector<vector<int>> graph;
    graph.push_back({1, 2});
    graph.push_back({3});
    graph.push_back({1, 4});
    graph.push_back({2, 5});
    graph.push_back({3, 5});


    cout << "深度优先遍历" << endl;
    dfs(graph, graph[0]);

    return 0;
}
