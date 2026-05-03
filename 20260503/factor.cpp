// level 0 - 약수 구하기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    for(int i = 1; i <= n/2; i++){
        if(n % i == 0) answer.push_back(i);
    }
    answer.push_back(n);
    return answer;
}

int main(){
    vector<int> v = solution(24);

    for(int i : v){
        cout<<i<<" ";
    }
    return 0;
}