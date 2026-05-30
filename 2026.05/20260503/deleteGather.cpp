// level 0 - 모음 제거 (delete gather)
#include <iostream>
#include <string>

using namespace std;

string solution(string my_string){
    string answer = "";
    char gather[5] = {'a', 'e', 'i', 'o', 'u'}; // + '\0'(자동 삽입)
    bool isGather = false;
    
    for(const char ch : my_string){
        isGather = false;
        for(char ch2 : gather){
            if(ch == ch2) isGather = true;
        }
        if(!isGather) answer.push_back(ch);
    }
    return answer;
}

int main(){
    cout<<solution("bus");
    return 0;
}