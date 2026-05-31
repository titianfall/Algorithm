// level 2 - H-index (과학자의 생산성과 영향력을 나타내는 지표입니다.)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 과학자가 발표한 논문의 인용회숫 배열 citations
int solution(vector<int> citations) {
    int hIndex = 0;

    // 인용된 논문수 h
    for(int h = 0; h <= citations.size(); h++){
        int count = 0;
        for(const int& citation : citations){ 
            if(citation >= h) count++; // h 이상 인용된 논문 수
        }
        // 인용횟수와 count 수가 같을 경우 이것이 H-index 가 된다.
        // 만일 그보다 작을 경우 인용된 최고 횟수가 h-index가 된다.
        if(count >= h){
            hIndex = h;
        }
    }

    return hIndex;
}

int solution2(vector<int> citations) {
    int hIndex = 0;
    for(const int& quotation : citations){
        int count = 0;
        for(const int& c : citations){
            if(c >= quotation) count++;
        }

        if(count >= quotation){
            if(quotation > hIndex) hIndex = quotation;   // 충분할 때
        } else {
            if(count > hIndex) hIndex = count;           // 부족할 때
        }
    }
    return hIndex;
}

int solution3(vector<int> citations){
    sort(citations.rbegin(), citations.rend());   // 내림차순
    int h = 0;
    for(int i = 0; i < (int)citations.size(); i++){
        if(citations[i] >= i + 1) h = i + 1;       // i+1번째 논문이 i+1회 이상?
        else break;
    }
    return h;
  }
int main(){
    // 발표 논문 5개, 3편의 논문은 3회 이상 인용, 나머지는 3회 이하 인용 이 과학자의 h-index는 3입니다.
    cout<<solution({3, 0, 6, 1, 5})<<endl;  // 3
    cout<<solution({1, 3, 1})<<endl;        // 1 
    cout<<solution({25, 8, 5, 3, 3})<<endl; // 3
    cout<<solution({4, 4, 4})<<endl;        // 3
    cout<<solution({100})<<endl;            // 1
    return 0;
}