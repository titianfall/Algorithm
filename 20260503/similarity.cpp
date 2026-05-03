// level 0 - 배열의 유사도
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;

    for(string str1 : s1){
        for(string str2 : s2){
            if(s1 == s2) answer++;
        }
    }


    
    return answer;
}

int solution2(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(string st1 : s1){
        auto it = find(s2.begin(), s2.end(), s1);
        if(it != s2.end()) answer++;
        // 중복이 된다면 erase 를 사용해서 제거해야함
        // s2.erase(s2.begin() + j); 
    }
    return answer;
}
int main(){
    cout<<solution({"a", "b", "c"}, {"n", "omg"});
    return 0;
}