// level 0 - 중복된 숫자 개수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    for(int i : array){
        if(i == n) answer++;
    }

    answer = count(array.begin(), array.end(), n);
    return answer;
}

int main(){
    cout<<solution({1, 1, 2, 3, 4, 5}, 1);
    return 0;
}