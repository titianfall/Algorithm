// level 2 - 이진 변환 반복하기 
// 1. x의 모든 0을 제거합니다. 
// 2. x의 길이 c 에 대해, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string input) {
    vector<int> answer;
    int deleteZeroCount = 0; // 제거한 0의 개수
    int rotateCount = 0; // 1이 될때까지 반복한 총 횟수
    int afterSize = 0;  // 제거 후 길이
    int result = 0; // 이진 변환 결과

    string str = "";
    while(true){
        rotateCount++;
        for(char& ch : input){
            if(ch == '0'){
                deleteZeroCount++;
                continue;
            }
            str += ch;
        }

        afterSize = str.size();
        // 이진수가 1인지 검사 (길이가 1이고 '1'이면 종료)
        if(afterSize == 1 && str == "1") break;

        // 정수를 이진수 문자열로 변환
        int num = afterSize;
        string binary = "";
        while(num > 0){
            binary = to_string(num % 2) + binary;
            num /= 2;
        }

        // 갱신
        input = binary;
        str = "";
    }
    
    answer.push_back(rotateCount);
    answer.push_back(deleteZeroCount);
    return answer;
}

int main(){
    vector<int> v = solution("110010101001");

    for(int it : v){
        cout<<it<<" ";
    }
    return 0;
}