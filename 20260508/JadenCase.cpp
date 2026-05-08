// level 2 - JadenCase 문자열 만들기 
// JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string input) {
    string answer = "";

    // 맨 처음, 공백 이후 대문자
    // bool isNew flag 사용
    bool isNew = true;
    for(char& ch : input){
        // 1. ' ' 일 경우 flag 상태 변경
        if(ch == ' '){
            answer += ch;
            isNew = true; 
        }
        // 일반 문자열 
        else{
            // isNew = true
            if(isNew){
                answer += toupper(ch);
                isNew = false;
            }
            // isNew = false;
            else answer += tolower(ch);
        }
    } 

    return answer;
}

int main(){
    string input = "3people unFollowed me";
    cout<<solution(input);
    return 0;
}