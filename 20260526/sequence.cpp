// level 2 - 연속 부분 수열 합의 개수
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <deque>
using namespace std;

// 다만 시간복잡도가 O(N^3) 이라는 단점이 있음
int solution2(vector<int> elements) {
    int size = elements.size();
    set<int> s;
    
    // vector를 deque로 옮김
    deque<int> dq(elements.begin(), elements.end());
    
    for (int windowSize = 1; windowSize <= size; windowSize++) {
        for (int start = 0; start < size; start++) {
            // 현재 deque의 앞에서부터 windowSize만큼 합산
            int sum = 0;
            for (int k = 0; k < windowSize; k++) {
                sum += dq[k];
            }
            s.insert(sum);
            
            // 한 칸 회전: 맨 앞을 떼서 맨 뒤로
            dq.push_back(dq.front());
            dq.pop_front();
        }
        // 한 windowSize에서 size번 회전하면 원래 상태로 돌아옴
        // (size번 회전 = 제자리)
    }
    
    return s.size();
}

// 시간복잡도를 제곱으로 만들 필요가 있음
int solution(vector<int> elements) {
    int size = elements.size();
    set<int> s;

    vector<int> prefix(2 * size + 1, 0);
    for(int i = 0; i < 2 * size; i++){
        prefix[i + 1] = prefix[i] + elements[i % size];
    }

    for(int windowSize = 1; windowSize <= size; windowSize++){
        for(int start = 0; start < size; start++){
            int sum = prefix[start + windowSize] - prefix[start];
            s.insert(sum);  
        }
    }

    return s.size();
}

int main(){
    cout<<solution({7, 9, 1, 1, 4})<<endl; // 18
    return 0;
}