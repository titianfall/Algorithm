// level 2 - 할인 행사
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string ,int> need;
    int total = 0;
    for(int i = 0; i < want.size(); i++){
        need[want[i]] = number[i];
        total += number[i];
    }

    int answer = 0;
    for(int i = 0; i <= discount.size() - total; i++){
        map<string, int> cnt;
        // 슬라이딩 윈도 인덱스크기
        for(int j = i; j < i + total; j++){
            if(need.count(discount[j])) cnt[discount[j]]++;
        }
        if(cnt == need) answer++;
    }

    // 가입하지 않는 경우
    return answer;
}

int main(){
    // 3
    cout<<solution({"banana", "apple", "rice", "pork", "pot"}, 
        {3, 2, 2, 2, 1}, 
        {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"})<<endl; 

    // 0
    cout<<solution({"apple"}, {10}, {"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"})<<endl;
    return 0;
}