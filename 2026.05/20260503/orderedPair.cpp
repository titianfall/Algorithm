// level 0 - 순서쌍의 개수 
// Number of ordered pair
#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    int answer = 0;
    
    // O(n / 2) 로 처리
    for(int i = 1; i <= n/2; i++){
        if(n % i == 0) answer++;
    }

    // n * 1의 경우가 계산이 안되기때문에 직접 추가 
    answer += 1;
    return answer;
}

// O(sqrt(n))
int rootSolution(int n){
    int answer = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            answer += 2;
            if(i * i == n) answer--;
        }
    }
    return answer;
}

int main(){
    cout<<solution(20)<<endl;
    cout<<rootSolution(20)<<endl;
    return 0;
}