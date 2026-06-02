// level 2 - 피로도
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count, int answer) {
    // cout<< "현재 피로도 " << k << endl <<  "현재 탐색 가능 횟수 " << count << endl;
    answer = max(answer, count); // 완전탐색을 하면서 가장 많은 탐색을 할 수 있도록 만듭니다.

    for (int i = 0; i < dungeons.size(); i++) {
        // cout << "현재 탐색하려는 던전 번호 " << i << endl;
        int needFatigue = dungeons[i][0];
        int consumeFatigue = dungeons[i][1];
        // cout << "던전 필요 피로도" << needFatigue << " " << consumeFatigue << endl;
        if (visited[i]) continue;
        if (k < needFatigue) continue;

        visited[i] = true;
        answer = dfs(k - consumeFatigue, dungeons, visited, count + 1, answer);
        visited[i] = false; // 한번의 dfs 탐색이 마무리 될 경우 돌아오며 플래그를 수정합니다.
    }

    return answer;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);

    answer = dfs(k, dungeons, visited, 0, answer);

    return answer;
}

int main() {
    cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl; // 3
    return 0;
}