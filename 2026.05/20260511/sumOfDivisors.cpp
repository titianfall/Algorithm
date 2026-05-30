// level 1 - 약수의 합
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0) answer += i;
    }
    return answer;
}

int main(){
    cout<<solution(12)<<endl; // 1 + 2 + 3 + 4 + 6 + 12 = 28
    cout<<solution(5)<<endl; //  1 + 5 = 6
    return 0;
}