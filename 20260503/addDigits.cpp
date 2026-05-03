// level 0 - 자릿수 더하기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    while(true){
        if(n/10 == 0) break;
        else{
            answer += n%10;
            n /= 10;
        }
    }
    // 문자열로 바꾸고 '0' = 48 빼주는 방법도 가능함
    answer += n;
    return answer;
}

int main(){
    cout<<solution(1234)<<endl;
    return 0;
}