// level 2 - 선인장 숨기기
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// m, n 격자 크기 
// h, w 선인장 크기
// drops 비가 내리는 순서
vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer;

    // h, w크기를 2차원 배열에서 순회하며 비를 맞는 순서를 누적

    // 0. 2차원 벡터 초기화(0 으로)
    vector<vector<int>> space(m, vector<int>(n, 0));
    //printSpace(space);
    
    // 2가지 생각
    // 1. 비가 오는 위치를 기록한 후 2x2 크기가 해당 위치에 포함되는 가장 작은 수를 기록 및 비교
    
    // 비가오는 순서를 기록 및 순서 증가
    int order = 1;
    for(vector<int> dropSpace : drops){
        int row = dropSpace[0];
        int col = dropSpace[1];
        space[row][col] = order++; 
    }
    
    // 최대 지연인 선인장의 위치를 저장
    int maxRow = 0;
    int maxCol = 0;
    int maxDelay = 0;
    for(int i = 0; i < space.size() - h + 1; i++){
        for(int j = 0; j < space[0].size() - w + 1; j++){

            int delay = INT_MAX;
            for(int r = 0; r < h; r++){
                for(int c = 0; c < w; c++){
                    if(space[i + r][j + c] == 0) continue;
                    else{
                        if(space[i + r][j + c] < delay){
                            delay = space[i + r][j + c];
                        }
                    }
                }
            }
            if(delay > maxDelay){
                maxDelay = delay;
                maxRow = i;
                maxCol = j;
            }
            // 마지막 제약조건 최대 지연 시간이 같을 경우
            // 가장 위쪽 행, 행이 똑같다면 그중에서도 가장 왼쪽 행을 출력하라. 
            else if(delay == maxDelay){
                if(i < maxRow || (i == maxRow && j < maxCol)){
                    maxRow = i;
                    maxCol = j;
                } 
            }
        }
    }

    answer.push_back(maxRow);
    answer.push_back(maxCol);
    // 가장 순서가 큰 위치를 벡터에 입력
    return answer;
}

int main(){
    vector<vector<int>> drops = {{0, 0}, {3, 1}, {1, 3}, {2, 4}, {1, 1}, {2, 2}, {2, 3}, {0, 4}};
    vector<int> answer = solution(4, 5, 2, 2, drops);

    for(int it : answer){
        cout<<it<<" ";
    }

    return 0;
}