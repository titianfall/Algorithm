// level 0 - 개미 군단
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    // 장군 5, 병정 3, 일 1
    
    for(int i = 5; i > 0; i -= 2){
        answer += hp/i;
        hp %= i;
    }
    return answer;
}

int main(){
    cout<<solution(23);
    return 0;
}