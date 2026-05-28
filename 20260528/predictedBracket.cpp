// level 2 - 예상 대진표
#include <iostream>

using namespace std;

int solution(int n, int a, int b){
    int answer = 0;

    while(a != b){
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
        // n/=2;
    }

    return answer;
}

int main(){
    cout<<solution(8, 4, 7);
    return 0;
}