#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_NUMBER = 100000;

int n, triangle[100][100];

// 1. 무식하게 완전 탐색하기
// (y, x) 위치까지 내려오기 전에 만난 숫자들의 합이 sum일 때,
// 맨 아래 줄까지 내려가면서 얻을 수 있는 최대 경로를 반환한다.
int path1(int y, int x, int sum) {
    // 기저 사례: 맨 아래 줄까지 도달했을 경우
    if(y == n - 1) return sum + triangle[y][x];

    // 합을 계산
    sum += triangle[y][x];
    return max(path1(y + 1, x + 1, sum), path1(y + 1, x, sum));
}
// 문제
// path1(y, x, sum)을 캐싱하려고 cache[y][x][sum]을 만들면,
// 1. sum의 최대값이 MAX_NUMBER * MAX_N이므로 사용해야 하는 메모리가 너무 크다.
// 2. 특정 입력에서는 완전 탐색처럼 동작한다. 예: 2의 거듭제곱 꼴인 삼각형

// 재귀 함수의 입력 걸러내기
// 1. y와 x는 재귀 호출이 풀어야 할 부분 문제를 지정한다. 이 두 입력이 정해지면
//    앞으로 만들 수 있는 경로들이 정해진다. 따라서 이들은 앞으로 풀어야 할 조각에 대한 정보다.
// 2. 반면 sum은 지금까지 어떤 경로로 이 부분 문제에 도달했는지를 나타낸다.
//    sum은 지금까지 풀었던 조각에 대한 정보다.

// path2(y, x) = (y, x)부터 시작해서 맨 아래 줄까지 내려가는 부분 경로의 최대 합을 반환한다.
// path2(y, x) = triangle[y][x] + max(path2(y + 1, x), path2(y + 1, x + 1))

// (y, x) 위치부터 맨 아래 줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int cache2[MAX_N][MAX_N];
int path2(int y, int x) {
    // 기저 사례: 맨 아래 줄에 도달했을 경우
    if(y == n - 1) return triangle[y][x];

    // 메모이제이션
    int& ret = cache2[y][x];
    if(ret != -1) return ret;

    return ret = triangle[y][x] + max(path2(y + 1, x), path2(y + 1, x + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;

    while(count--) {
        cin >> n; // 2 <= n <= 100
        memset(cache2, -1, sizeof(cache2));

        for(int y = 0; y < n; ++y) {
            for(int x = 0; x <= y; ++x) {
                cin >> triangle[y][x];
            }
        }

        cout << path2(0, 0) << '\n';
    }
    return 0;
}
