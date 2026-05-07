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
    queue<tuple<int,int,int>> q;  // {row, col, 거리}

    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    // 코드 중복을 없애는 관용적인 패턴임
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty()) {
        // row, col, dist 값이 tuple로 초기화됨
        auto [r, c, dist] = q.front(); 
        q.pop();

        if (maps[r][c] == target) return dist;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (visited[nr][nc] || maps[nr][nc] == 'X') continue;
            visited[nr][nc] = true;
            q.push({nr, nc, dist + 1});
        }
    }
    return -1;  // 도달 불가
  }

int solution(vector<string> maps) {
    pair<int, int> start;
    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[0].size(); j++)
            if (maps[i][j] == 'S') 
                start = {i, j};

    int toL = bfs(maps, start, 'L');   // 시작 → 레버
    if (toL == -1) return -1;

    // 레버 위치 찾기
    pair<int,int> lever;
    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[0].size(); j++)
            if (maps[i][j] == 'L') 
                lever = {i, j};

    int toE = bfs(maps, lever, 'E');   // 레버 → 출구
    if (toE == -1) return -1;

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