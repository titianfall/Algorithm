#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> h; // 각 판자의 높이를 저장하는 배열

// 무식하게 풀기 - O(n^2)
int bruteForce() {
    int ret = 0;
    int N = h.size();

    // 가능한 left, right 조합 순회
    for(int left = 0; left < N; ++left) {
        int minHeight = h[left];
        for(int right = left; right < N; ++right) {
            minHeight = min(minHeight, h[right]);
            ret = max(ret, (right - left + 1) * minHeight);
        }
    }

    return ret;
}

// 분할 정복 알고리즘의 설계
// 1. 가장 큰 직사각형을 왼쪽 부분 문제에서 잘라낼 수 있다.
// 2. 가장 큰 직사각형을 오른쪽 부분 문제에서 잘라낼 수 있다.
// 3. 가장 큰 직사각형은 왼쪽 부분문제와 오른쪽 부분 문제에 걸쳐있다.

// 양쪽에 걸친 경우에 대하여 - 무조건 양쪽의 판자를 포함한다는 것이 힌트이다.
// 해당 직사각형을 양쪽으로 한칸씩 확대해 나간다고 생각하면 된다.

// h[left, right] 구간에서 찾아낼 수 있는 가장 큰 사각형의 넓이를 반환한다.
int solve(int left, int right) {
    // 기저 사례: 판자가 하나밖에 없는 경우
    if(left == right) return h[left];

    // [left, mid], [mid + 1, right]의 두 구간으로 문제를 분할한다.
    int mid = (left + right) / 2;

    // 분할한 문제를 부분 문제 1, 2 방식으로 해결
    int ret = max(solve(left, mid), solve(mid + 1, right));

    // 부분 문제 3
    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);

    // [mid, mid + 1] 만 포함하는 너비 2인 사각형을 고려한다.
    ret = max(ret, height * 2); 

    // 사각형이 입력 전체를 덮을 때까지 확장해 나간다.
    while(lo > left || hi < right) {
        // 항상 높이가 더 높은 쪽으로 확장한다.
        if(hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
            ++hi;
            height = min(height, h[hi]);
        }
        else {
            --lo;
            height = min(height, h[lo]);
        }

        // 확장한 후 사각형의 넓이 
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret; 
}
int main() {
    // 입력을 직접 쓰지 않고, 테스트할 높이 배열을 {} 안에 넣는다.
    vector<vector<int>> testCases = {
        {7, 1, 5, 9, 6, 7, 3},
        {1, 4, 4, 4, 4, 1, 1},
        {1, 8, 2, 2}
    };

    for(const vector<int>& heights : testCases) {
        h = heights;
        int boardCount = h.size();

        int maxArea = bruteForce();
        cout << "bruteForce() : " << maxArea << '\n';

        maxArea = solve(0, boardCount - 1);
        cout << "solve() : " << maxArea << '\n';
    }
    return 0;
}

/*
// 온라인 저지 제출 시 사용하는 기존 cin 입력 방식
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;

    while (count--) {
        int boardCount;
        cin >> boardCount;

        h.resize(boardCount);
        for (int i = 0; i < boardCount; ++i) {
            cin >> h[i];
        }

        cout << solve(0, boardCount - 1) << '\n';
    }

    return 0;
}
*/
