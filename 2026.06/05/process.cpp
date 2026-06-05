// level 2 - 프로세스(스택/큐)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 시간복잡도 O(n ^ 2)
// 공간복잡도 O(n) = q : O(n) + prorities : O(n) 
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; // 인덱스, 우선순위를 같이 저장

    // O(n)
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
    }

    // 모든 프로세스가 완료되어 종료될 때까지 반복
    while(!q.empty()){
        // 현재 프로세스를 가져오고
        pair<int, int> currentProcess = q.front();
        q.pop();

        // 현재 프로세스보다 우선순위가 높은 프로세스가 남아 있는지 확인
        bool hasHigher = false; 

        // O(n)
        for(int process : priorities) {
            if(process > currentProcess.second){
                hasHigher = true;
                break;
            }
        }
        
        if(hasHigher) {
            // 더 높은 우선순위가 있을 경우
            q.push(currentProcess); // 큐 갱신
        }
        else{ 
            answer++; // 현재 프로세스를 실행

            // 찾는 순서의 프로세스일 경우 
            if(currentProcess.first == location){
                return answer;
            }

            // 실행된 프로세스를 남은 우선순위를 목록에서 제거
            vector<int>::iterator it = find(priorities.begin(), priorities.end(), currentProcess.second); // O(n)
            priorities.erase(it); // O(n)
        }
    }
    return answer;
}

int main(){
    cout<<solution({2, 1, 3, 2}, 2)<<endl; // 1 
    cout<<solution({1, 1, 9, 1, 1, 1}, 0)<<endl; // 5
    return 0;
}