// level 1 - 정수 제곱근 판별
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// n이 어떤 정수의 제곱이면 (제곱근+1)^2 리턴, 아니면 -1 리턴
long long solution(long long n) {
    long long answer = 0;

    long long x = sqrtl((long double)n); // n의 제곱근의 정수 부분

    if (x * x == n) {           // n이 x의 제곱이면
        answer = (x + 1) * (x + 1);
    } else {                    // 정수 제곱이 아니면
        answer = -1;
    }

    return answer;
}

#include <iostream>
int main(){
    cout << solution(121) << endl; // 144
    cout << solution(3) << endl;   // -1
    return 0;
}