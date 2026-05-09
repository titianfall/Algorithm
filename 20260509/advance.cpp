// level 2 - 선인장 숨기기 (슬라이딩 윈도우 최솟값 O(m*n))
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<vector<int>> space(m, vector<int>(n, INT_MAX)); // 비 안 맞는 칸은 INT_MAX (무한 지연)
    int order = 1;
    for (auto& d : drops)
        space[d[0]][d[1]] = order++; // 각 칸에 비가 몇 번째로 내리는지 기록

    // [1단계] 행 방향 슬라이딩 윈도우 최솟값 (크기 w)
    // rowMin[i][j] = i행에서 j~j+w-1 열 범위의 최솟값
    vector<vector<int>> rowMin(m, vector<int>(n - w + 1));
    for (int i = 0; i < m; i++) {
        deque<int> dq; // 덱에 열 인덱스를 저장, 앞이 항상 현재 윈도우의 최솟값 위치
        for (int j = 0; j < n; j++) {
            while (!dq.empty() && space[i][dq.back()] >= space[i][j]) 
                dq.pop_back(); // 새 값보다 크거나 같은 뒤쪽 원소 제거 (최솟값 후보 아님)
            
            dq.push_back(j); // 현재 인덱스 추가

            // 인덱스가 저장되는 dq와 인덱스 비교
            if (dq.front() < j - w + 1)
                dq.pop_front(); // 윈도우 범위 벗어난 앞쪽 원소 제거
            
            // j가 윈도우의 크기보다 커질 경우 
            // 특정 위치에서 버틸수 있는 시간들을 2차원 벡터에 저장 
            if (j >= w - 1) 
                rowMin[i][j - w + 1] = space[i][dq.front()]; // 윈도우가 완성되면 최솟값 저장
        }
    }

    // [2단계] 열 방향 슬라이딩 윈도우 최솟값 (크기 h)
    // rowMin의 각 열에서 h 크기 윈도우 최솟값 = h×w 윈도우 전체 최솟값
    int maxDelay = 0, maxRow = 0, maxCol = 0;
    for (int j = 0; j <= n - w; j++) {
        deque<int> dq; // 덱에 행 인덱스를 저장
        for (int i = 0; i < m; i++) {
            while (!dq.empty() && rowMin[dq.back()][j] >= rowMin[i][j]) 
                dq.pop_back(); // 새 값보다 크거나 같은 뒤쪽 원소 제거
            dq.push_back(i); // 현재 인덱스 추가

            if (dq.front() < i - h + 1) 
                dq.pop_front(); // 윈도우 범위 벗어난 앞쪽 원소 제거

            if (i >= h - 1) { // 윈도우가 완성된 경우
                int delay = rowMin[dq.front()][j]; // h×w 윈도우에서 가장 먼저 맞는 비의 순서
                int row = i - h + 1; // 현재 윈도우의 시작 행
                if (delay > maxDelay) { // 더 오래 버티는 위치 발견
                    maxDelay = delay; 
                    maxRow = row; 
                    maxCol = j;
                }
                else if (delay == maxDelay) { // 동일한 지연이면 위쪽 행, 같은 행이면 왼쪽 열 우선
                    if (row < maxRow || (row == maxRow && j < maxCol)) {
                        maxRow = row; 
                        maxCol = j;
                    }
                }
            }
        }
    }

    return {maxRow, maxCol};
}

int main() {
    vector<vector<int>> drops = {{0, 0}, {3, 1}, {1, 3}, {2, 4}, {1, 1}, {2, 2}, {2, 3}, {0, 4}};
    vector<int> answer = solution(4, 5, 2, 2, drops);
    for (int it : answer) cout << it << " ";
    return 0;
}
