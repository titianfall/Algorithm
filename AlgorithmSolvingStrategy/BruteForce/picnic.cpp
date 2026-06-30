#include <iostream>
#include <vector>

using namespace std;

int n;
bool areFriends[10][10];

// taken[i] = i번째 학생이 이미 짝을 찾았으면 true, 아니면 false이다.
int countDuplicationPairings(bool taken[10]){
    // 기저 사례 - 모든 학생이 짝을 찾았으면 한 가지 방법을 찾은 것이다.
    bool finished = true;
    for(int i = 0; i < n; ++i){
        if(!taken[i]) finished = false;
    }
    if(finished) return 1;
    int ret = 0;
    // 서로 친구인 두 학생을 찾아 짝을 지어준다.
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!taken[i] && !taken[j] && areFriends[i][j]){
                taken[i] = taken[j] = true;
                ret += countDuplicationPairings(taken);
                taken[i] = taken[j] = false;
            }
        }
    }
    return ret; // 해당 함수를 출력해보면 정답과 다르게 나온다. (굉장히 흔하게 마주치는 경우이다.)
    // 1. 같은 학생 쌍을 두 번 짝을 짓는다. 2. 다른 순서로 짝지어 주는 것을 서로 다른 경우로 센다.
}

// 재귀 호출 알고리즘은 답의 수에 정비례한다.
// 9 x 7 x 5 x 3 x 1 = 945개이다.
// 즉 시간복잡도는 이중팩토리얼인 O((n-1)!!)이 된다.

// 중복을 줄이기 위해
// 각 단계에서 남아 있는 학생 중 가장 번호가 빠른 학생의 짝을 지어준다.
int countPairings(bool taken[10]){
    // 남은 학생 중 가장 번호가 빠른 학생을 찾는다.
    int firstFree = -1;
    for(int i = 0; i < n; ++i){
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }

    // 기저 사례 - 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
    if(firstFree == -1) return 1;
    int ret = 0;
    // 이 학생과 짝지을 학생을 결정한다.
    for(int pairWith = firstFree + 1; pairWith < n; ++pairWith){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}
int main(){

    return 0;
}
