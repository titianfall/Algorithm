// level 2 - 기능 개발
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses
// 각 작업의 갭라 속도가 적힌 정수 배열 speeds 가 주어집니다.
vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> answer; // 한번에 배포되는 작업들의 수를 기록
    int n = progresses.size();
    int currentDeploy = 0;

    // 각 작업들을 병렬적으로 진행되며,
    // 작업이 끝나도 앞선 작업이 완성되지 않았을 경우 배포를 대기합니다.
    while(currentDeploy < n){
        // 하루동안 작업
        for(int i = 0; i < n; i++){
            if(progresses[i] < 100) progresses[i] += speeds[i]; // 작업 진행
        }

        // 가장 먼저 배포해야 하는 작업이 완료되었으면 바로 배포 시작
        if(progresses[currentDeploy] >= 100){
            int count = 0; // 동시에 배포하는 개수

            // 배포를 할 것이 아직 남았거나, 진행이 완료 되었을 경우
            while(currentDeploy < n && progresses[currentDeploy] >= 100){
                count++;
                currentDeploy++;
            }

            answer.push_back(count);
        }
    }
    return answer;
}

// 개쩐다..
vector<int> solution2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        // 작업 완료까지 걸리는 시간을 계산
        // (99 - 95) / 1 + 1 = 5일
        // (99 - 93) / 1 + 1 = 7일
        // (99 - 30) / 30 + 1 = 3일
        day = (99 - progresses[i]) / speeds[i] + 1; 

        // 첫 배포 or 이번 기능은 이전 기능보다 이후의 기능임
        if (answer.empty() || max_day < day)
            answer.push_back(1); // 새 기능 단독 배포
        else
            ++answer.back(); // 마지막 배포 묶음의 개수를 1만큼 증가시킵니다.

        if (max_day < day)
            max_day = day;
    }

    return answer;
}

int main(){
    vector<int> v = solution({93, 30, 55}, {1, 30, 5});
    for(int i : v) cout<<i<<" ";
    return 0;
}