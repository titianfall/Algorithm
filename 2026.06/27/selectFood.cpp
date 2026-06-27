#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N; // 친구 수
int M; // 음식 수

// canEat[person][food] == 1 이면 person이 food를 먹을 수 있음
vector<vector<int>> canEat;

// 시간복잡도: O(N * menu.size())
// 최악의 경우 menu.size() == M 이므로 O(N * M)
bool canEverybodyEat(const vector<int>& menu) {
    for (int person = 0; person < N; person++) {
        bool ok = false;

        for (int food : menu) {
            if (canEat[person][food] == 1) {
                ok = true;
                break;
            }
        }

        if (!ok) return false;
    }

    return true;
}

// 음식마다 선택 / 선택 안 함 두 가지 경우를 탐색
// 부분집합 개수: 2^M
// 각 마지막 단계에서 canEverybodyEat() 호출: O(N * M)
// 최종 시간복잡도: O(2^M * N * M)
int selectMenu(vector<int>& menu, int food) {
    if (food == M) {
        if (canEverybodyEat(menu)) {
            return menu.size();
        }
        return INF;
    }

    // food번 음식을 선택하지 않는 경우
    int ret = selectMenu(menu, food + 1);

    // food번 음식을 선택하는 경우
    menu.push_back(food);

    /*
        menu는 재귀 함수들이 같이 사용하는 "현재 선택한 음식 목록"이다.

        그래서 food번 음식을 선택한 경우를 탐색하려면
        일단 menu에 food를 넣고 재귀 호출을 한다.

        재귀 호출이 끝나면 food를 다시 빼야 한다.
        그래야 다음 탐색에서 "food를 선택하기 전 상태"로 돌아갈 수 있다.

        이처럼 선택하고, 재귀로 탐색한 뒤, 다시 선택을 취소하는 방식을
        백트래킹이라고 한다.

        visited[x] = true;
        dfs(next);
        visited[x] = false;

        와 같은 구조라고 보면 된다.
    */
    ret = min(ret, selectMenu(menu, food + 1));

    // food번 음식을 선택한 경우의 탐색이 끝났으므로 원상복구
    menu.pop_back();

    return ret;
}

int main() {
    N = 4;
    M = 6;

    /*
        행: 사람
        열: 음식

        canEat[person][food] == 1 이면
        person번 사람이 food번 음식을 먹을 수 있다는 뜻이다.

        1: 먹을 수 있음
        0: 먹을 수 없음
    */
    canEat = {
        // 음식: 0  1  2  3  4  5
        { 1, 0, 1, 0, 0, 0 }, // 0번 사람
        { 0, 1, 1, 0, 0, 0 }, // 1번 사람
        { 0, 0, 0, 1, 1, 0 }, // 2번 사람
        { 0, 0, 0, 0, 1, 1 }  // 3번 사람
    };

    cout << "[시간복잡도 분석]\n";
    cout << "canEverybodyEat(menu): O(N * menu.size()), 최악 O(N * M)\n";
    cout << "selectMenu(menu, food): O(2^M * N * M)\n";
    cout << "main 초기 데이터 설정: O(N * M)\n";
    cout << "최종 시간복잡도: O(2^M * N * M)\n";
    cout << "공간복잡도: O(N * M + M)\n\n";

    vector<int> menu;
    int answer = selectMenu(menu, 0);

    cout << "최소 음식 개수: " << answer << '\n';

    return 0;
}