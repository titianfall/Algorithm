// 시계 맞추기 
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr int INF = 987654321;
constexpr int SWITCHES = 10;
constexpr int CLOCKS = 16;

// switchClocks[스위치 번호][시계 번호]
// 연결된 시계는 'x', 연결되지 않은 시계는 '.'으로 표시한다.
const char linked[SWITCHES][CLOCKS + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x..",
};

bool areAligned(const vector<int>& clocks) {
    for(int clock : clocks){
        if(clock != 12){
            return false;
        }
    }
    return true;
}

void push(vector<int>& clocks, int swtch){
    for(int clock = 0; clock < CLOCKS; ++clock){
        if(linked[swtch][clock] == 'x'){
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch){
    // 기저 조건 : 모든 시계가 12시를 가리킨다면 바로 돌아간다.
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
    
    int ret = INF; // 스위치를 0번 ~ 3번 누르는 경우를 모두 시도한다.
    for (int cnt = 0; cnt < 4; ++cnt){
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    // push(clocks, swtch)가 4번 호출되었으니, clocks는 원래와 같은 상태가 된다.
    return ret;
}

int main(){
    /*
    예제 입력
    2
    12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
    12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6

    예제 출력
    2
    9
    */

    int cases;
    cin >> cases;

    while(cases--){
        vector<int> clocks(CLOCKS);
        for(int i = 0; i < CLOCKS; ++i){
            cin >> clocks[i];
        }

        int answer = solve(clocks, 0);
        cout << (answer == INF ? -1 : answer) << '\n';
    }
}
