// level 2 - 숫자변환하기
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    if(x == y) return 0;

    // false 로 초기화하며 아직 방문하지 않은 상태로 설정함 
    vector<bool> visited(y + 1, false);
    
    queue<pair<int, int>> q; // 현재 값, 연산 횟수

    q.push({x, 0}); // 시작값(10)은 삽입 
    visited[x] = true; // x는 방문 처리

    // 큐가 빌 때까지 bfs 반복
    while(!q.empty()){
        int current = q.front().first; // 현재 값
        int count = q.front().second; // 현재까지 사용한 연산 횟수
        q.pop(); // 사용한 원소 큐에서 제거

        // 연산 세가지 비교
        vector<int> nexts = {current + n, current * 2, current * 3};

        // 더하기 2 3 각각 처리
        for(int next : nexts){
            // level 1 : 10 > 15, 20, 30 
            // level 2 : 15 > 20, 30, 35, 20 > 25, 40(2 + 1 횟수 반환), 60
            if(next == y) return count + 1; // 목표값 + 1 횟수 반환 

            // !y 이면서 아직 방문하지 않았다면 최단 경로가 없는 경우이므로 탐색 
            if(next < y && !visited[next]){
                visited[next] = true; // 방문 처리
                q.push({next, count + 1}); // 큐에 삽입
            }
        }
    }
    return -1;
}

int main(){
    cout<<solution(10, 40, 5)<<endl;
    return 0;
}