#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000;

int n, m;

// 1. 경우의 수 세기 (비가 올 확률과 맑을 확률이 각각 50%일 때)
int cache[MAX_N][2 * MAX_N + 1];

// 달팽이가 days일 동안 climbed미터를 기어올라 왔다고 할 때,
// m일 전까지 n미터를 기어올라갈 수 있는 경우의 수
int climb(int days, int climbed) {
    // 기저 사례: m일이 모두 지난 경우
    if(days == m) return climbed >= n ? 1 : 0;

    // 메모이제이션
    int& ret = cache[days][climbed];
    if(ret != -1) return ret;

    return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}
// 최종 확률은 climb(0, 0) / 2^m 이다.
// 모든 날씨 조합의 확률이 같기 때문에 성립하는 계산이며,
// m이 커지면 2^m 과 경우의 수 자체가 int 범위를 넘으므로 작은 m에서만 쓸 수 있다.

// 2. 확률을 직접 반환하기 (매일 75%의 확률로 비가 올 때)
double cache2[MAX_N][2 * MAX_N + 1];

// 달팽이가 days일 동안 climbed미터를 올라왔을 때,
// m일 안에 n미터 이상 올라갈 확률을 반환한다.
double climb2(int days, int climbed) {
    // 기저 사례: m일이 모두 지난 경우
    if(days == m) return climbed >= n ? 1.0 : 0.0;

    // 메모이제이션
    double& ret = cache2[days][climbed];
    if(ret != -1.0) return ret;

    // 각 갈래로 갈 확률을 가중치로 곱해서 더한다.
    return ret = 0.25 * climb2(days + 1, climbed + 1)
               + 0.75 * climb2(days + 1, climbed + 2);
}

int main() {
    int C;
    scanf("%d", &C);

    while(C--) {
        scanf("%d %d", &n, &m); // 1 <= n, m <= 1000

        // double 배열은 memset(cache2, -1, ...)으로 초기화하면 NaN이 되므로 fill()을 쓴다.
        for(int i = 0; i < m; ++i) {
            fill(cache2[i], cache2[i] + 2 * m + 1, -1.0);
        }

        printf("%.10f\n", climb2(0, 0));
    }
    return 0;
}
