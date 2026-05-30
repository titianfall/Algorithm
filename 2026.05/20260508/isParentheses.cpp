// level 2 - 올바른 괄호 
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string input)
{
    stack<char> s;
    
    // 소괄호만 사용 
    for(char& ch : input){
        if(ch == '(') s.push(ch);
        else{
            if(s.empty()) return false;
            s.pop();
        }
    }

    return s.empty();
}

int main(){
    string input = ")()(";
    cout<<solution(input);
    return 0;
}