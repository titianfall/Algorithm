// level 2 - 행렬의 곱셈 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int r = arr1.size();
    int c = arr2[0].size();
    vector<vector<int>> answer(r, vector<int>(c, 0));

    // 행
    for(int i = 0; i < r; i++){
        // 열
        for(int j = 0; j < c; j++){
            int num = 0;
            for(int k = 0; k < arr1[0].size(); k++){
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> v = solution({{1, 4}, {3, 2}, {4, 1}}, {{3, 3}, {3, 3}});

    cout << v.size() << " " << v[0].size() << endl;
    for(auto& r : v){
        for(auto& c : v[0]){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}