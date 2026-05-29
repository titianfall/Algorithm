// level 0 - 편지 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string message) {
    int answer = message.length() * 2;
    return answer;
}

int main(){
    cout<<solution("happy birthday!");
    return 0;
}