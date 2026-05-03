// level 0 - 쵀댓값 만들기(1)
#include <iostream>
#include <vector>

using namespace std;

// bool compare(int a, int b) return a > b;
int solution(vector<int> numbers){
    int answer = 0;

    int max = 0;
    for(int i = 0; i < numbers.size() - 1; i++){
        if(numbers[i] == 0) continue;
        for(int j = i + 1; j < numbers.size(); j++){
            if(numbers[i] * numbers[j] > max)
                max = numbers[i] * numbers[j];
        }
        
    }
    // sort(numbers.begin(), numbers.end(), compare);
    // answer = numbers[numbers.size() - 1] * numbers[numbers.size() - 2];
    answer = max;
    return answer;
}

int main(){
    cout<<solution({1,2,3,4,5})<<endl;
    return 0;
}