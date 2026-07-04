// TSP, Traveling Sales-man Problem 문제
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

constexpr int MAX = 10;

using namespace std;

const double INF = numeric_limits<double>::max();

int n; // 도시의 수
double dist[MAX][MAX]; // 두 도시 간의 거리를 저장하는 배열

// 시간복잡도는 O(n!) = (n * (n - 1)!) 수준이다.
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength){
    // 기저 사례 : 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
    if(path.size() == static_cast<size_t>(n))
        return currentLength + dist[path[0]][path.back()];

    double ret = INF; // 매우 큰 값으로 초기화
    // 다음 방문할 도시들에 대해 모두 시도해본다.
    for(int next = 0; next < n; ++next){
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;

        // 나머지 경로를 재귀 호출을 통해 완성, 가장 짧은 경로의 길이를 얻는다.
        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main(){
    int cases;
    cin >> cases;

    cout << fixed << setprecision(10);

    while(cases--){
        cin >> n;

        for(int y = 0; y < n; ++y){
            for(int x = 0; x < n; ++x){
                cin >> dist[y][x];
            }
        }

        vector<int> path;
        vector<bool> visited(n, false);

        path.push_back(0);
        visited[0] = true;

        cout << shortestPath(path, visited, 0.0) << '\n';
    }

    return 0;
}
