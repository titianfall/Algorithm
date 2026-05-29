// level 2 - n^2 배열 자르기 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    // 메모리 초과로 터짐
    // vector<vector<int>> arr2D(0, {n, 0});
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         arr2D[i][j] = max(i, j);
    //     }
    // }

    // 배열의 인덱스를 활용해서 
    // 해당 인덱스중 가장 큰 인덱스에 1만큼 더하면 
    // 추가적인 배열을 생성하고 초기화하지 않아도 문제를 해결할수있다.
    for(long long i = left; i <= right; i++){
        long long row = i / n;
        long long col = i % n;
        answer.push_back(max(row, col) + 1);
    }
    return answer;
}

int main(){
    vector<int> v = solution(3, 2, 5); // 3, 2, 2, 3
    for(int& it : v) cout << it << " ";
    cout << endl;

    v = solution(4, 7, 14);
    for(int& it : v) cout << it << " ";
    cout << endl;

    return 0;
}