// level 0 - 주사위의 개수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 1;

    // box의 길이는 3이다.
    // 0 : 가로, 1 : 세로, 2 : 높이
    // 주사위는 n,n,n 의 부피를 가짐

    // 가로 * 세로 * 높이 개수를 각각 곱하면 됨 
    for(int size : box){
        answer *= size/n;
    }
    return answer;
}

int main(){
    cout<<solution({1, 1, 1}, 1);
    return 0;
}