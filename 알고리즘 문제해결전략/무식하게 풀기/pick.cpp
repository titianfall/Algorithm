#include <iostream>
#include <vector>

using namespace std;

// void pickFor(int n)
// {
//     for (int i = 0; i < n; ++i){
//         for (int j = i + 1; j < n; ++j){
//             for (int k = j + 1; k < n; ++k){
//                 for (int l = k + 1; l < n; ++l){
//                     cout << i << " " << j << " " << k << " " << l << "\n";
//                 }
//             }
//         }
//     }
// }

void printPick(const vector<int>& picked){
    for(int number : picked) {
        cout << number << " ";
    }
    cout << "\n";
}

void pickRecursive(int n, vector<int>& picked, int toPick){
    // 재귀 호출에는 기저 사례가 필요하다.
    // 골라야 하는 수가 더 이상 없을 경우 해당 조합을 출력하고 다시 돌아간다.
    if(toPick == 0) {
        printPick(picked);
        return;
    } 

    // 가장 작은 수를 가져온다. 비어 있을 경우 0부터 시작하고, 아니라면 마지막으로 고른 수 다음부터 시작한다.
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int next = smallest; next < n; ++next){
        picked.push_back(next);
        pickRecursive(n, picked, toPick - 1);
        picked.pop_back();
    }
}

void pick(int n, int toPick){
    vector<int> picked;
    pickRecursive(n, picked, toPick);
}

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = v.size();

    // pickFor(n); // 무식하게 for문을 돌리는 방법이다.
    pick(n, 4);
    // 0, 1, 2, 3 / ... / 4, 5, 6, 7까지 만들어진다.
    return 0;
}
