#include <iostream>
#include <vector>
using namespace std; 

int count = 1;
void printPicked(vector<int>& v){
    cerr<<"cerr " << count++ << " : ";
    for(int i : v) cout<<i<<" "; 
    cout<<"\n";
}

void pick(int n, vector<int>& picked, int toPick){
    // 기저 : 더 고를 원소가 없을경우
    if(toPick == 0) {
        printPicked(picked);
        return;
    }
    
    // 고를 수 있는 가장 작은 번호로 비교
    int smallest = picked.empty() ? 0 : picked.back() + 1;

    // 원소를 하나 골라 backtraking 시작
    for(int next = smallest; next < n; ++next){
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}
int main(){
    vector<int> v;

    pick(7, v, 4);
    return 0;
}