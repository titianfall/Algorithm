// level 0 - 점의 위치 구하기
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> dot){
    int answer = 0;
    if(dot[0] > 0){
        if(dot[1] > 0) return 1;
        else return 4;
    }
    else if(dot[0] < 0){
        if(dot[1] > 0) return 2;
        else return 3;
    }
    return answer;
}

int main(){
    vector<int> dot = {2, 4};
    cout<<solution(dot);
    return 0;
}