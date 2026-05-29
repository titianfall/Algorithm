// level 0 - 가장 큰 수 찾기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;

    int maxIdx = 0;
    int max = array[0];

    for(int i = 1; i < array.size(); i++){
        if(array[i] > max){
            max = array[i];
            maxIdx = i; 
        }
    }

    answer.push_back(max);
    answer.push_back(maxIdx);
    return answer;
}

vector<int> solution2(vector<int> array){
    vector<int> answer;
    auto t = max_element(array.begin(), array.end());
    answer.push_back(*t);
    answer.push_back(distance(array.begin(), t));

    return answer;
}
// c++ 프로그램의 진입점으로 필수이다. 
int main(){
    vector<int> v = solution({1, 8, 3});

    for(int it : v){
        cout<<it<<" ";
    }
    return 0;
}