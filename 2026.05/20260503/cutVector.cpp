// level 0 - 배열 자르기
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2){
    vector<int> answer;
    
    for(int i = num1; i <= num2; i++){
        answer.push_back(numbers[i]);
    }
    return answer;
}
int main(){
    vector<int> numbers = {1, 2, 3, 4, 5};
    numbers = solution(numbers, 1, 3);
    for(int it : numbers){
        cout<<it<<" ";
    }
    return 0;
}