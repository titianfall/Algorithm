#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAX_N = 100;

int n, triangle[MAX_N][MAX_N];

int cache[MAX_N][MAX_N];
// (y, x)에서 시작해서 맨 아래 줄까지 내려가는 경로의 최대 합을 반환한다.
int path2(int y, int x) {
    // 기저 사례: 맨 아래 줄에 도달한 경우
    if(y == n - 1) return triangle[y][x];

    int& ret = cache[y][x];
    if(ret != -1) return ret;

    return ret = triangle[y][x] + max(path2(y + 1, x), path2(y + 1, x + 1));
}

int countCache[MAX_N][MAX_N];
// (y, x)에서 시작해서 맨 아래 줄까지 내려가는 경로 중 최대 경로의 개수를 반환
int count(int y, int x) {
    // 기저 사례: 맨 아래줄에 도달한 경우
    if(y == n - 1) return 1;

    int& ret = countCache[y][x];
    if(ret != -1) return ret;

    ret = 0;

    // 두 아래 칸 중 더 큰 값을 주는 쪽으로만 내려가야 최대 경로가 된다.
    // 두 값이 같으면 양쪽 모두 최대 경로이므로 개수를 더한다.
    if(path2(y + 1, x) >= path2(y + 1, x + 1)) ret += count(y + 1, x);
    if(path2(y + 1, x) <= path2(y + 1, x + 1)) ret += count(y + 1, x + 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;

    while(C--) {
        cin >> n; // 2 <= n <= 100
        memset(cache, -1, sizeof(cache));
        memset(countCache, -1, sizeof(countCache));

        for(int y = 0; y < n; ++y) {
            for(int x = 0; x <= y; ++x) {
                cin >> triangle[y][x];
            }
        }

        cout << count(0, 0) << '\n';
    }
    return 0;
}
