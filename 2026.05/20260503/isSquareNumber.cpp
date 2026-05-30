// level 0 - 제곱수 판별하기
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 2;

    int s = (int)sqrt(n);
    // pow(s, 2) == n
    if(s * s == n) answer = 1;
    return answer;
}

int main(){
    cout<<solution(144);
    return 0;
}