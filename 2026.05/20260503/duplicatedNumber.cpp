// level 0 - 중복된 숫자 개수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    for(int i : array){
        if(i == n) answer++;
    }

    answer = count(array.begin(), array.end(), n);
    return answer;
    // accumulate(first, last, init, op)
    // accumulate(first = v.begin(), last = v.end(), init = vector<int>{}, op = [](vector<int> acc, int x) { acc.push_back(x); return acc;})
    // return accumulate(array.begin(), array.end(), 0, [n](int& x, int& i) { return x += i == n;});
}

int main(){
    cout<<solution({1, 1, 2, 3, 4, 5}, 1);
    return 0;
}