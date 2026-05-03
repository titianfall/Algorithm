// level 0 - 대문자와 소문자
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string my_string){
    string answer = "";
    for(const char ch : my_string){
        if(islower(ch)) answer += toupper(ch);
        // ch -= 32 해서 대문자로 바꿀수 있음
        // a = 97
        else if(isupper(ch)) answer += tolower(ch);
        // ch += 32 해서 소문자로 바꿔도 됨 
        // A = 65
    }
    
    return answer;
}

int main(){
    cout<<solution("cccCCC");
    return 0;
}