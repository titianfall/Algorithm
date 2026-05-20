// level 2 - 카펫
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int n, m;
    // 이게뭐지? 많이 당황스럽다.

    // brown 5000 수준이므로 제곱을 해도 1초 미만임 
    int size = brown + yellow;
    int temp;
    // 1. 3부터 나누어가며 yellow의 개수와 비교
    for(int h = 3; h <= size; h++){
        if(size % h != 0) continue;
        
        int w = size/h; // 가로
        if(w < h) break;

        // 왜 2개씩? 
        if((w - 2) * (h - 2) == yellow)
            return {w, h};
    }

    return {n, m};
}

int main(){
    vector<int> v = solution(10, 2);
    for(int it : v){
        cout<<it<<" ";
    }
    return 0;
}