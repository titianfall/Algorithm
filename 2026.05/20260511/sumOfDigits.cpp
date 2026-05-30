// level 1 - 자릿수의 합
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;
    while(true){
        answer += n%10;
        n = n/10;
        if(n == 0) break;
    }

    return answer;
}

int main(){
    cout<<solution(123)<<endl; // 6
    cout<<solution(987)<<endl; // 24
    return 0;
}