// level 2 - 괄호 회전하기 
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool isPair(queue<char> q){
    bool pair = true;
    stack<char> s;

    while(!q.empty()){
        char ch = q.front();
        q.pop();
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else {
            if(s.empty()) return false; 

            if(s.top() == '(' && ch == ')' || 
                   s.top() == '{' && ch == '}' ||
                   s.top() == '[' && ch == ']' ){
                s.pop();
                   }
            else return false;
        }
    }
    
    if(!s.empty()) return false;
    return pair;
}


int solution(string s) {
    int answer = 0;
    queue<char> q;

    for(char& ch : s){
        q.push(ch);
    }
    answer = 0;
    for(int i = 0; i < s.size(); i++){
        char ch = q.front();
        q.pop();
        q.push(ch);

        if(isPair(q)) answer++;
    }
    return answer;
}

int main(){
    cout<<solution("[](){}")<<endl; // 3
    cout<<solution("}]()[{")<<endl; // 2
    cout<<solution("[)(]")<<endl; // 0 
    cout<<solution("}}}")<<endl; // 0
    return 0;
}