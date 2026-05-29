// level 2 - 미로 탈출
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int bfs(vector<string>& maps, pair<int,int> start, char target) {
    int rows = maps.size();
    int cols = maps[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<pair<int,int>, int>> q;  // {row, col, 거리}
    // tuple 을 지원할 경우 queue<tuple<int, int, int>> 도 가능함
    q.push({{start.first, start.second}, 0});
    visited[start.first][start.second] = true;

    // 동서남북 중복 코드를 삭제하는 일반적인 방법
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    // 완전탐색을 마칠 때까지 반복
    while (!q.empty()) {
        // pair<int, int> pos 라고 생각하면 편함 
        auto [pos, dist] = q.front(); // pos (row, col)
        auto [r, c] = pos; 
        // auto [r, c, dist] // tuple 방식
        q.pop();

        if (maps[r][c] == target) return dist;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            // 행이나 열이 0보다 작거나 최대 사이즈보다 클 수 없음
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            // X인 위치는 없는 경로임
            if (visited[nr][nc] || maps[nr][nc] == 'X') continue;
            visited[nr][nc] = true;
            q.push({{nr, nc}, dist + 1});
        }
    }
    // bfs를 통해 탐색하였지만 나오지 못한 경우
    return -1;
}

int solution(vector<string> maps) {
    // 1. step 1 : 시작지점(START) - 레버
    pair<int, int> start; 
    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[0].size(); j++)
            if (maps[i][j] == 'S') 
                start = {i, j};

    int toL = bfs(maps, start, 'L');   // 시작 → 레버
    if (toL == -1) return -1;

    // 2. step 2 : 레버 - 탈출(END)
    pair<int,int> lever;
    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[0].size(); j++)
            if (maps[i][j] == 'L') 
                lever = {i, j};

    int toE = bfs(maps, lever, 'E');   // 레버 → 출구
    if (toE == -1) return -1;

    // 3. step 3 : step 1 + step 2 
    return toL + toE;
}

int main(){
    vector<string> maps = {
        "SOOOL",
        "XXXXO",
        "OOOOO",
        "OXXXX",
        "OOOOE"
    };
    cout<<solution(maps);
    return 0;
}