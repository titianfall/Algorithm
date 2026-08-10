// 폴리오미노: POLY
// n개의 정사각형으로 만들 수 있는 세로 단조 폴리오미노의 수를 센다.
// 세로 단조란 어떤 가로줄도 폴리오미노를 두 번 이상 교차하지 않는다는 뜻이라,
// 각 가로줄의 정사각형들은 항상 한 덩어리로 연속해 있다.
#include <cstring>
#include <iostream>

using namespace std;

constexpr int MAX_N = 100;          // 정사각형 수의 최댓값 (1 <= n <= 100)
constexpr int MOD = 10 * 1000 * 1000;   // 답이 커지므로 이 수로 나눈 나머지를 출력한다.

int cache[MAX_N + 1][MAX_N + 1];    // poly()의 메모이제이션 캐시

// n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의
// 정사각형을 포함하는 세로 단조 폴리오미노의 수를 MOD로 나눈 나머지를 반환한다.
int poly(int n, int first) {
    // 기저 사례: 남은 정사각형을 첫 줄이 전부 가져가면 아래로 더 쌓을 것이 없다.
    // 이 모양은 한 가지뿐이므로 1을 반환한다.
    if (n == first) return 1;

    // 메모이제이션 적용
    int& ret = cache[n][first];
    if (ret != -1) return ret;

    // 서로 겹치지 않는 여러 경우의 수를 더해 나갈 것이므로 덧셈의 항등원인 0에서 시작한다.
    // 최댓값을 찾는 문제였다면 여기서 아주 작은 값이나 음의 무한대로 시작했겠지만,
    // 이 문제는 개수를 세는 문제라 "아직 아무것도 세지 않은 상태"가 곧 0이다.
    // 아래 반복문이 한 번도 돌지 않는 경우는 없다. n > first이므로 n - first >= 1이라
    // second는 최소 한 번은 1이 되기 때문이다.
    ret = 0;

    // 남은 n - first개의 정사각형으로 만드는 폴리오미노의 첫 줄 크기를 second라 하고,
    // 가능한 모든 second에 대해 경우의 수를 더한다.
    for (int second = 1; second <= n - first; ++second) {
        // 위 줄(first개)과 아래 폴리오미노의 첫 줄(second개)은 적어도 한 칸에서 맞닿아야
        // 하므로, 둘을 좌우로 밀어 붙이는 방법은 first + second - 1가지다.
        int add = second + first - 1;

        // 오버플로 확인: 루프 조건이 second <= n - first라 second + first <= n이고,
        // 따라서 add는 n - 1 <= 99를 넘지 않는다. poly()의 반환 값은 MOD - 1 = 9,999,999
        // 이하이므로 곱은 최대 99 * 9,999,999 = 989,999,901로 int 범위 안에 들어온다.
        add *= poly(n - first, second);
        add %= MOD;

        ret += add;
        ret %= MOD;
    }
    return ret;
}

// n개의 정사각형으로 만들 수 있는 세로 단조 폴리오미노의 수를 반환한다.
// 첫 줄에 들어간 정사각형의 수로 분류하면 모든 폴리오미노가 정확히 한 분류에만
// 속하므로, 각 분류의 개수를 그냥 더하면 된다.
int countPoly(int n) {
    int ret = 0;
    for (int first = 1; first <= n; ++first) {
        ret += poly(n, first);
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);    // C 표준 입출력과의 동기화를 끊어 cin/cout 속도를 올린다.
    cin.tie(nullptr);               // cin 앞에서 cout을 자동으로 flush하지 않게 한다.

    // poly()는 테스트 케이스의 입력에 의존하지 않는 순수 함수다.
    // 그래서 케이스마다 지울 필요 없이 시작할 때 한 번만 -1로 채우면 된다.
    memset(cache, -1, sizeof(cache));

    int C;
    cin >> C;                       // 테스트 케이스의 수 (1 <= C <= 50)

    while(C--) {
        int n;
        cin >> n;                   // 정사각형의 수 (1 <= n <= 100)
        cout << countPoly(n) << '\n';
    }
    return 0;
}
