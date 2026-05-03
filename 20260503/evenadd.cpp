// level 0 - 짝수의 합
#include <iostream>

using namespace std;

int solution(int n){
    int answer = 0;
    for(int i = 0; i <= n; i += 2){
        answer += i;
    }
    return answer;
}
int main(){
    cout<<solution(10)<<endl;
    return 0;
}