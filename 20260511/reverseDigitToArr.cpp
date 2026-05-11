// level 1 - 자릿수 뒤집어 배열로 만들기
#include <iostream>
#include <vector>

using namespace std;
// 왜 n은 long long 타입인가
// 뒤집었을때 21억을 초과하지않는 숫자도 가능하기 때문에 long long 타입으로 받음
vector<int> solution(long long n) {
    vector<int> answer;
    while(n) {
        answer.push_back(n % 10);
        n /= 10;
    }
    return answer;
}

int main(){
    vector<int> v = solution(12345);
    for(int it : v) cout << it << " ";
    return 0;
}