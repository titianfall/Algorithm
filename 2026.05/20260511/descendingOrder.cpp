// level 1 - 정수 내림차순으로 배치하기 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    // string str = to_string(n);
    vector<int> v;
    while(n){
        v.push_back(n % 10);
        n /= 10;
    }

    // sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; i++){
        int idx = i;
        for(int j = i + 1; j < v.size(); j++){
            if(v[j] > v[idx]) idx = j;
        }
        swap(v[i], v[idx]);
    }
    
    for(int i = 0; i < v.size(); i++){
        answer = answer * 10 + v[i];
    }
    return answer;
}

int main(){
    cout<<solution(118372); //873211
    return 0;
}