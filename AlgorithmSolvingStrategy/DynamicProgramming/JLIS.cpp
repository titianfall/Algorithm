#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;

// index가 -1이면 아직 아무 원소도 선택하지 않은 가상 시작점이다.
// 입력에는 int의 최솟값도 등장할 수 있으므로, 모든 int보다 작은
// long long의 최솟값을 가상 시작점의 값으로 사용한다.
const long long NEGINF = numeric_limits<long long>::min();

int n, m, A[100], B[100];
// indexA, indexB는 -1도 사용하므로 실제 캐시에서는 각각 1을 더해 저장한다.
int cache[101][101];

// min(A[indexA], B[indexB]), max(A[indexA], B[indexB])로 시작하는
// 합친 증가 부분 수열의 최대 길이를 반환한다.
// 단, indexA == indexB == -1 혹은 A[indexA] != B[indexB]라고 가정한다.
int jlis(int indexA, int indexB) {
    // (-1, -1) 상태도 cache[0][0]에 저장할 수 있도록 인덱스를 한 칸 옮긴다.
    int& ret = cache[indexA + 1][indexB + 1];
    if(ret != -1) return ret;

    // 현재 상태의 두 시작 원소를 센 길이로 시작한다.
    // 최초 호출 jlis(-1, -1)에서는 두 가상 원소까지 세므로 최종 답에서 2를 뺀다.
    ret = 2;

    // index가 -1이면 배열의 -1번 칸에 접근하지 않고 가상 최솟값을 사용한다.
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);

    // 다음 원소는 지금까지 선택한 A, B의 마지막 값보다 모두 커야 한다.
    long long maxElement = max(a, b);

    // 다음 원소를 A에서 고르는 모든 경우를 시도한다.
    for(int nextA = indexA + 1; nextA < n; ++nextA) {
        if(maxElement < A[nextA]) {
            // jlis()는 부분 수열 자체가 아니라 최대 길이를 반환한다.
            // A[nextA]를 이번에 선택했으므로 재귀 호출의 결과에 1을 더한 뒤,
            // 지금까지 찾은 최대 길이 ret과 비교한다.
            ret = max(ret, jlis(nextA, indexB) + 1);
        }
    }

    // 다음 원소를 B에서 고르는 경우도 같은 방식으로 시도한다.
    for(int nextB = indexB + 1; nextB < m; ++ nextB) {
        if(maxElement < B[nextB]) {
            // B에서만 새 원소를 골랐으므로 indexA는 그대로 유지한다.
            ret = max(ret, jlis(indexA, nextB) + 1);
        }
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;

    // 각 테스트 케이스마다 두 수열의 길이와 원소를 입력받는다.
    while (count--) {
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> B[i];
        }

        // 테스트 케이스마다 이전 계산 결과를 지운다.
        memset(cache, -1, sizeof(cache));

        // (-1, -1)은 두 수열 모두 아직 원소를 선택하지 않은 가상 시작점이다.
        // jlis()가 가상 원소 두 개를 포함해 길이를 계산하므로 최종 결과에서 2를 뺀다.
        cout << jlis(-1, -1) - 2 << '\n';
    }

    return 0;
}
