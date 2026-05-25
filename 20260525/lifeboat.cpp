// level 2 - 구명 보트 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;
    while(left <= right){
        answer++;
        if(people[left] + people[right] > limit) right--;
        else if(people[left] + people[right] <= limit) {
            left++;
            right--;
        }
    }

    return answer;
}

int main(){
    cout<<solution({70, 50, 80, 50}, 100)<<endl; // 3
    cout<<solution({70, 80, 50}, 100)<<endl; // 3
    return 0;
}