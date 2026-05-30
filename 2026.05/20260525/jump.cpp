// level 2 - 멀리 뛰기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0; // 정수가 21억이라고 가정하면 그 경로에 도달하는방법은 정수의 최대값을 넘을수있다.
    const int MOD = 1234567;
    // n개의 칸
    // 1칸 또는 2칸의 점프가 가능
    int size = n;
    int two = 0;

    while(size >= two){
        // size 배열에 2가 two 개 들어가는 자리수 
        long long c = 1; 

        for(int i = 0; i < two; i++){
            c = c * (size - i) / (i + 1);
            // c 연산값이 long long 값을 초과하여 오버플로우 발생
        }
        // 모듈러
        answer = (answer + c) % MOD; 

        // 1 두개 제거, 2 하나 추가
        size--; 
        two++;
    }
    return answer;
}

// 이래서 써보는걸 망각하면 안됨...
long long solution2(int n){
    // ways(n) = ways(n-1) + ways(n-2)
    if (n <= 2) return n;

    const int MOD = 1234567;

    long long waysTwoBack = 1;  // ways(i-2): 시작 시 ways(1)=1
    long long waysOneBack = 2;  // ways(i-1): 시작 시 ways(2)=2
    long long waysHere    = 0;  // ways(i):   매 턴 새로 계산할 값

    // i = 3부터 n까지 한 칸씩 전진
    for (int i = 3; i <= n; i++) {
        waysHere = (waysOneBack + waysTwoBack) % MOD;

        // 다음 턴을 위해 한 칸씩 밀어주기
        waysTwoBack = waysOneBack; 
        waysOneBack = waysHere; 
    }

    return waysOneBack; // ways(n)
}

int main(){
    cout<<solution(4)<<endl;
    cout<<solution(3)<<endl;

    cout<<solution(2000)<<endl; // -25752 실제 오버플로우 발생 확인
    // 즉, 조합에 대한 직접 계산은 더이상 불가능함을 확인함

    cout<<solution2(4)<<endl;
    cout<<solution2(2000)<<endl; // 694725

    return 0;
}