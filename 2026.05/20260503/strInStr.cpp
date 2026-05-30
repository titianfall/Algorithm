// level 0 - 문자열안에 문자열
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 2;

    if(str2.size() > str1.size()) return 2;

    for(int i = 0; i <= str1.size() - str2.size(); i++){
        string tmp = str1.substr(i, str2.size()); // i부터 시작해서 str2.size()개 
        if(tmp == str2) return 1;
    }
    
    return answer;

    // string::find 못찾으면 string::npos 반환 
    // return str1.find(str2) != string::npos ? 1: 2;
}

int main(){
    cout<<solution("ab6CDE443fgh22iJKlmn1o", "6CD");
    return 0;
}