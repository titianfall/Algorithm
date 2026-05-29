// level 1 - 같은 숫자는 싫어 (스택, 큐)
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer ;
    answer.push_back(arr[0]);
    for(int it : arr){
        if(answer.back() != it){
            answer.push_back(it);
        }
    }
    return answer;
}

int main(){
    vector<int> arr = {1,1,3,3,0,1,1};

    arr = solution(arr);

    for(int it : arr){
        cout<<it<<" ";
    }
    return 0;
}