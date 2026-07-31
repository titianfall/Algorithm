#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MOD = 1000000007;

int cache[MAX_N + 1];
// 2 * width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례: width 가 1 이하일 때
    if(width <= 1) return 1;

    // 메모이제이션
    int& ret = cache[width];
    if(ret != -1) return ret;

    // tiling()의 반환값은 최대 MOD - 1 이므로 두 개를 더해도 int 범위를 넘지 않는다.
    return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 캐시가 테스트 케이스의 입력에 의존하지 않으므로 한 번만 초기화한다.
    memset(cache, -1, sizeof(cache));

    int C;
    cin >> C; // C <= 50

    while(C--) {
        int n;
        cin >> n; // 1 <= n <= 100
        cout << tiling(n) << '\n';
    }
    return 0;
}
