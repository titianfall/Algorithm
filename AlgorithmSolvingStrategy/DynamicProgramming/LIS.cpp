// LIS: Longest Increasing Sub-sequence
// 주어진 수열에서 얻을 수 있는 가장 긴 증가 부분 수열(LIS)의 길이를 구한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 500;

int n;
int S[MAX_N];

// 1) 완전 탐색
// 수열 A의 LIS 길이를 반환하는 재귀 함수.
int lis(const vector<int>& A) {
    // 기저 사례: A가 텅 비어 있을 때
    if (A.empty()) return 0;

    int ret = 0;
    for (int i = 0; i < A.size(); ++i) {
        // A[i]보다 뒤에 있으면서 더 큰 숫자들만 모아 B를 만든다.
        vector<int> B;
        for (int j = i + 1; j < A.size(); ++j) {
            if (A[i] < A[j]) B.push_back(A[j]);
        }
        // A[i] 한 개(+1)에 B의 LIS를 이어 붙인다.
        ret = max(ret, 1 + lis(B));
    }
    return ret;
}

// 2) 메모이제이션
// S[start]에서 시작하는 LIS 길이를 반환한다. 시작 위치는 main에서 밖으로 순회한다.
int cache2[MAX_N];
int lis2(int start) {
    int& ret = cache2[start];
    if (ret != -1) return ret;

    ret = 1; // S[start]는 항상 포함되므로 길이는 최소 1이다.
    for (int next = start + 1; next < n; ++next) {
        if (S[start] < S[next]) {
            ret = max(ret, lis2(next) + 1);
        }
    }
    return ret;
}

// 3) 시작 위치 고정 (가상 시작점)
int cache3[MAX_N + 1]; // 가상 시작점(-1)까지 담으려 +1
// start == -1은 실제 수열보다 앞에 있는 가상의 시작점(값 -무한대)을 뜻하며,
// 모든 원소를 다음 숫자로 시도할 수 있다.
int lis3(int start) {
    int& ret = cache3[start + 1]; // 음수 인덱스를 피하려 start + 1로 접근한다.
    if (ret != -1) return ret;

    ret = 1; // 가상 시작점(-1)에서 얻은 길이는 마지막에 1을 빼서 보정한다.
    for (int next = start + 1; next < n; ++next) {
        if (start == -1 || S[start] < S[next]) {
            ret = max(ret, lis3(next) + 1);
        }
    }
    return ret;
}

// 4) O(n log n)
// 각 길이의 증가 수열 중 마지막 값의 최솟값을 C[]에 유지한다.
int lisFast() {
    vector<int> C;
    for (int i = 0; i < n; ++i) {
        // S[i]가 들어갈 자리를 이분 탐색으로 찾는다.
        auto it = lower_bound(C.begin(), C.end(), S[i]);
        if (it == C.end()) C.push_back(S[i]); // 가장 크면 길이를 늘린다
        else *it = S[i]; // 아니면 그 자리를 갱신한다
    }
    return C.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> S[i];
        }

        // 가상 시작점에서 출발한 길이에는 가상 원소 한 개가 포함되므로 1을 뺀다.
        memset(cache3, -1, sizeof(cache3));
        cout << lis3(-1) - 1 << '\n';
    }
    return 0;
}
