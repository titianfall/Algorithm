//level 0 - 세균 증식
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int t) {
    return n * (1 << t);
    // pow(n, t + 1)보다 빠르며 
    // 곱셈, 로그 없이 비트 연산
    // 부동소수점 오차가 없으며 
    // t 가 지수일때 사용 가능
}

int main(){
    cout<<solution(2, 10);
    return 0;
}