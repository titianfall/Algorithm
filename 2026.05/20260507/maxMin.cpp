// programmers level 2 - 최댓값과 최솟값 
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string solution(string input){
    
    string str = "";
    int max = INT_MIN;
    int min = INT_MAX;

    input += ' '; // 마지막에 ' ' 을 달아 루프 안에서 모두 처리 
    for (char ch : input) {
        // 공백을 만나면 stoi 활용 max min 판별 
        if (ch == ' ') {
            if (!str.empty()) {
                int n = stoi(str);
                if (n > max) max = n;
                if (n < min) min = n;
                str = "";
            }
        } 
        // 1. 공백 이전까지 숫자를 채움 
        else {
            str += ch;
        }
    }
    
    return to_string(min) + " " + to_string(max);
}
int main(){

    cout<<solution({"1 2 3 4"});
    return 0;
}