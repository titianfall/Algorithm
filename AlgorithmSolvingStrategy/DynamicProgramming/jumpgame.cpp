#include <iostream>
#include <cstring>

using namespace std;

// 격자의 크기는 100 x 100 = 10,000
int n, board[100][100]; // 연속된 데이터 영역에 저장
bool jump(int y, int x) {
    // 기저 사례: 게임판 밖을 벗어난 경우
    if(y >= n || x >= n) return false; 
    // 기저 사례: 마지막 칸에 도착한 경우
    if(y == n - 1 && x == n - 1) return true;

    int jumpSize = board[y][x];
    return jump(y + jumpSize, x) || jump(y, x + jumpSize); 
}

// 참조적 투명 함수인 jump는 캐시를 사용할 수 있다.
int cache[100][100];
int jump2(int y, int x) {
    // 기저 사례: 게임판 밖을 벗어난 경우
    if(y >= n || x >= n) return false; 
    // 기저 사례: 마지막 칸에 도착한 경우
    if(y == n - 1 && x == n - 1) return true;

    // 메모이제이션
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;
    while(count--) {
        // 캐시 초기화 
        memset(cache, -1, sizeof(cache));
        cin >> n;

        for(int y = 0; y < n; ++y) {
            for(int x = 0; x < n; ++x) {
                cin >> board[y][x]; // 각 칸의 숫자는 1 ~ 9이다. 마지막 칸은 0이다.
            }
        }
    }
    return 0; 
}