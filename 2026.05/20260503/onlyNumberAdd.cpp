// level 0 - 숨어있는 숫자의 덧셈
#include <iostream>
#include <string>
#include <cctype> // 문자 단위 판별
using namespace std;

int solution(string my_string){
    int answer = 0;

    // 문자열중 숫자만 판단하여 answer에 합산
    for(const char ch : my_string){
        // 정수판단 isdigit
        // 알파벳 판단 isalpha
        // 알파벳 숫자 isalnum
        // 공백 isspace 
        if(isdigit(ch)) answer += ch -'0';
    }
    return answer;
}

int main(){
    cout<<solution("aAb1B2cC34oOp")<<endl;
    return 0;
}