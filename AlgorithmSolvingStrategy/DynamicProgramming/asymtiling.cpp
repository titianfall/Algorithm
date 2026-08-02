#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX_N = 100;          // 사각형 너비의 최댓값 (1 <= n <= 100)
constexpr int MOD = 1000000007;     // 답이 커지므로 이 수로 나눈 나머지를 출력한다.

int cache[MAX_N + 1]; // tiling()의 메모이제이션 캐시

// 2 * width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례. width가 0이면 아무것도 놓지 않는 한 가지, 1이면 세로 타일 하나를 놓는 한 가지.
    if(width <= 1) return 1;

    // 메모이제이션 적용
    int& ret = cache[width];
    if(ret != -1) return ret;

    // 맨 왼쪽 세로줄을 세로 타일 하나로 덮으면 width - 1이,
    // 가로 타일 두 개로 덮으면 width - 2가 남는다. 두 경우는 겹치지 않으므로 더한다.
    // 두 값 모두 MOD - 1 이하라 더해도 int 범위(약 21억)를 넘지 않는다.
    return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

// [접근 1] 전체 타일링의 수에서 대칭 타일링의 수를 빼서 비대칭 타일링의 수를 구한다.
int asymmetric(int width) {
    // width가 홀수면 대칭 타일링은 한 종류뿐이다.
    // 정가운데 세로줄은 반드시 세로 타일 하나로 덮이고, 왼쪽 절반을 채우면
    // 오른쪽 절반은 대칭으로 자동 결정되므로 대칭 타일링의 수는 tiling(width / 2)다.
    // tiling()은 나머지를 반환하므로 뺄셈 결과가 음수일 수 있다. MOD를 미리 더해 막는다.
    if(width % 2 == 1)
        return (tiling(width) - tiling(width / 2) + MOD) % MOD;

    // width가 짝수면 대칭 타일링이 두 종류라 둘 다 빼 줘야 한다. 먼저 전체 수에서 시작한다.
    int ret = tiling(width);

    // 첫 번째 종류: 정가운데에서 절반으로 나뉘고 양쪽이 서로 대칭인 경우.
    // 왼쪽 절반을 채우는 방법의 수와 1:1 대응된다.
    ret = (ret - tiling(width / 2) + MOD) % MOD;

    // 두 번째 종류: 정가운데 세로줄 둘을 가로 타일로 덮고 나머지가 서로 대칭인 경우.
    // 가로 타일이 차지한 한 칸을 뺀 나머지를 채우는 방법의 수와 1:1 대응된다.
    ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;

    return ret;
}

int cache2[MAX_N + 1]; // asymmetric2()의 메모이제이션 캐시.

// [접근 2] 양쪽 끝을 덮은 타일의 조합으로 분류해 비대칭 타일링의 수를 직접 센다.
// 모든 비대칭 타일링은 아래 네 분류 중 정확히 하나에 속하므로 네 값을 더하면 된다.
int asymmetric2(int width) {
    // 기저 사례. 너비가 2 이하인 사각형의 타일링은 모두 좌우 대칭이라 비대칭은 0개다.
    // width - 4가 음수로 내려가는 재귀 호출도 여기서 함께 걸러진다.
    if(width <= 2) return 0;

    // 메모이제이션 적용
    int& ret = cache2[width];
    if(ret != -1) return ret;

    // 양쪽 끝이 모두 세로 타일. 끝 타일끼리는 대칭이므로 가운데(width - 2)가 비대칭이어야 한다.
    ret = asymmetric2(width - 2) % MOD;

    // 양쪽 끝이 모두 가로 타일. 마찬가지로 가운데(width - 4)가 비대칭이어야 한다.
    ret = (ret + asymmetric2(width - 4)) % MOD;

    // 왼쪽 끝은 세로, 오른쪽 끝은 가로. 끝 타일끼리 이미 비대칭이므로
    // 가운데(width - 3)는 대칭이든 아니든 상관없다. 그래서 tiling()을 쓴다.
    ret = (ret + tiling(width - 3)) % MOD;

    // 왼쪽 끝은 가로, 오른쪽 끝은 세로. 위와 좌우가 뒤집힌 별개의 패턴이라
    // 같은 tiling(width - 3)을 한 번 더 더한다.
    ret = (ret + tiling(width - 3)) % MOD;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);    // C 표준 입출력과의 동기화를 끊어 cin/cout 속도를 올린다.
    cin.tie(nullptr);               // cin 앞에서 cout을 자동으로 flush하지 않게 한다.

    // 두 캐시 모두 테스트 케이스의 입력에 의존하지 않는 순수 함수의 캐시다.
    // 그래서 케이스마다 지울 필요 없이 시작할 때 한 번만 -1로 채우면 된다.
    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));

    int C;
    cin >> C;                       // 테스트 케이스의 수 (1 <= C <= 50)

    while(C--) {
        int n;
        cin >> n;                   // 사각형의 너비 (1 <= n <= 100)
        cout << asymmetric(n) << '\n';  // asymmetric2(n)으로 바꿔도 같은 답이 나온다.
    }
    return 0;
}
