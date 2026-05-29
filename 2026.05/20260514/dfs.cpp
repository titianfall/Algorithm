#include <iostream>
#include <vector>

#define MAX_NUM 1000

using namespace std;

int count = 0;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int vertex){
    for(int i = 0; i < (int) graph[vertex].size(); i++){
        int curV = graph[vertex][i];
        if(!visited[curV]){
            visited[curV] = true;
            count++;
            dfs(graph, visited, curV);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(MAX_NUM + 1);
    vector<bool> visited(MAX_NUM + 1, false);
    int v1, v2;
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // 1에서 도달할수 있는 vertex들을 구함
    visited[1] = true;
    dfs(graph, visited, 1);
    cout << count;
    return 0;
}
