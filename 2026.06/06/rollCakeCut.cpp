// level 2 - 롤케이크 자르기
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// O(n log n) 까지의 시간복잡도만 허용됨 
// topping.size() 1,000,000길이

// O(n)
int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> right;

    for(int x : topping) {
        right[x]++;
    }

    unordered_set<int> left; // 0 ~ n;
    for(int i = 0; i < topping.size(); i++){
        int x = topping[i];

        left.insert(x);

        right[x]--;
        if(right[x] == 0) right.erase(x); // O(1) 해시테이블

        if(left.size() == right.size()) answer++;
    }

    return answer;
}

int main(){
    cout<<solution({1, 2, 1, 3, 1, 4, 1, 2})<<endl; // 2
    cout<<solution({1, 2, 3, 1, 4}); // 0
    return 0;
}