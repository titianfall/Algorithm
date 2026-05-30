// level 1 - 문자열을 정수로 바꾸기
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

// 1. stoi 사용 - + - 를 인식하여 정수로 변환해줌
int solution1(string s){
    int answer = 0;
    answer = stoi(s); 
    // stringStream(s);
    // ss >> answer;
    return answer;
}

// 2. stringstream 사용 
int solution2(string s){
    stringstream ss(s);
    int answer;
    ss >> answer;
    return answer;
}

// 3. 직접 구현 
int solution3(string s){
    int answer = 0;
    // 0. 부호 확인 
    int sign = 1; // 양수 1, 음수 -1
    if(s[0] == '-') sign = -1;
    
    // 1. 나머지 수들을 (s[n]-'0')을 통해 정수로 변환 
    int i = 0; // 양수 0, 음수 1부터 인덱싱
    if(sign == -1) i = 1;
    for(i; i < s.size(); i++){
        answer = answer * 10 + (s[i] - '0') ;  
        // 숫자들이 단순히 더해져 -9 출력 
    }

    return answer * sign;
}
int main(){
    cout<<solution1("1234")<<endl;
    //cout<<solution2("1234")<<endl;
    //cout<<solution3("1234");
    return 0;
}