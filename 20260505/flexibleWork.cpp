// level 1 - 유연근무제
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday){
    int answer = 0;
    int n = schedules.size();
    int days = timelogs[0].size();

    for(int i = 0; i < n; i++){
        // 마감시간을 분 단위로 변환 (10분 추가 후)
        int deadline = (schedules[i] / 100) * 60 + (schedules[i] % 100) + 10;
        
        bool isLate = false;
        int day = startday;  // 사람마다 startday 초기화
        
        for(int j = 0; j < days; j++){
            // 주말(토=6, 일=7)은 건너뜀
            if(day != 6 && day != 7){
                int arrival = (timelogs[i][j] / 100) * 60 + (timelogs[i][j] % 100);
                if(arrival > deadline){
                    isLate = true;
                }
            }
            day = (day % 7) + 1;  // 1~7 순환
        }
        
        if(!isLate) answer++;
    }
    return answer;
}

int solution2(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); ++i) {
        bool match = true;
        int time = schedules[i] + 10;
        if (time % 100 > 59) time += 40;
        // 40분을 추가로 더해주는 방식으로 
        // 855> 865 > 905 이런식으로 처리할수도 있었음 

        for (int j = 0; j < 7; ++j) {
            int day = (startday + j) % 7;

            if (day != 6 && day != 0 && timelogs[i][j] > time) {
                match = false;
                break;
            }
        }

        if (match) {
            ++answer;
        }
    }
    return answer;
}
int main(){
    // 출근 희망시각
    vector<int> schedules = {700, 800, 1100};
    // 일주일 동안 출근한 시각 
    vector<vector<int>> timelogs = 
    {
        {710, 2359, 1050, 700, 650, 631, 659}, 
        {800, 801, 805, 800, 759, 810, 809},
        {1105, 1001, 1002, 600, 1059, 1001, 1100}
    };

    cout<< solution(schedules, timelogs, 5);
    return 0;
}