// level 2 - 캐시(카카오)
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// 시간복잡도 O(n * cities.size() * cacheSize)
int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size() * 5;
    int answer = 0; // 최적 db 캐시값

    // LRU 알고리즘을 사용한다.
    int hit = 1, miss = 5;
    int n = cities.size();
    deque<string> cash; // 캐시 역할을 하는 덱

    for(string& city : cities){
        // 대소문자 구분을 안하기 위한처리
        // std::transfrom - 룩업 테이블 방식이므로 비용이 매우 적음
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        deque<string>::iterator it = find(cash.begin(), cash.end(), city);
        if(it != cash.end()){
            answer += hit;

            cash.erase(it); // 기존 위치 제거
            cash.push_back(city); // 가장 최근으로 갱신
        }
        else{
            // 캐시가 가득찼을 경우에만
            if(cash.size() >= cacheSize)
                cash.pop_front();
            cash.push_back(city);

            answer += miss;
        }
    }

    return answer;
}

int main(){
    cout<<solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}); 
    // 50
    return 0;
}