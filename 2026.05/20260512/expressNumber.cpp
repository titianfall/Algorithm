// level 2 - 숫자의 표현 
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 자연수 n을 연속한 자연수들로 표현 하는 방법
int solution(int n) {
    int answer = 0;

    for (int start = 1; start <= n; start++) {
        int tmp = 0;
        for (int i = start; i <= n; i++) {
            tmp += i;
            if (tmp == n) { answer++; break; }
            if (tmp > n) break;
        }
    }

    return answer;
}
int main(){
    cout<<solution(15);
    return 0;
}