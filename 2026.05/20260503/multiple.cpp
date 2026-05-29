// level 0 - n의 배수 고르기
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for(int i : numlist){
        if(i % n == 0) answer.push_back(i);
    }
    return answer;
    // accumulate 람다함수
    // return accumulate(numlist.beign(), numlist.end(), vector<int>(), [n](vector<int>& v, int& a){ if(!(a%n))v.push_back(a); return v;});
}

int main(){
    vector<int> v = solution(3, {4, 5, 6, 7, 8, 9, 10, 11, 12});

    for(int i : v){
        cout<<i<<" ";
    }
    return 0;
}