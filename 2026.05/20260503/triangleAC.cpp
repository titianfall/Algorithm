// level 0 - 삼각형의 완성조건(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> sides){
    int answer = 1;

    sort(sides.begin(), sides.end());
    // sort 3번째 인자 cmp 
    // 람다로 
    // [](const int& a, const int& b) { return a < b };
    if(sides[2] >= sides[0] + sides[1]) answer = 2;
    return answer;
}

int main(){
    vector<int> sides = {1, 2, 3};
    cout<<solution(sides);
    return 0;
}