#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 문자열의 길이는 1,000,000 제한이 있다. 
// 1초로 생각하면 n * log n까지만 허용한다는 소리다.

// vector로 받고 삭제하면 간단히 해결할 수 있을것 같긴하다만.. 
// stack 활용
int solution(string input){
    int answer = 0; //default 실패
    stack<int> s;
    // 끝에서만 작업을 하면 N이 나오지만 그러지 않을경우에는 무조건 시간초과가 나게된다.
    
    for(char& ch : input){
        if(!s.empty() && s.top() == ch){
            s.pop();
        }
        else{
            s.push(ch);
        }
    }

    return s.empty() ? 1 : 0;
}

int main(){
    // baabaa > bbaa > aa > "" 
    cout<<solution("baabaa")<<endl; // 1 성공
    cout<<solution("cdcd")<<endl; // 0
    return 0;
}