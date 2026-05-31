// level 2 - 의상
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> count;
    // 의상 종류만 카운트
    for(const auto& cloth : clothes){
        count[cloth[1]]++; // clothes[0][1] ~ clothes[n][1]
    }

    int answer = 1;
    for(const auto& [cloth, cnt] : count){
        answer *= (cnt + 1);
    }
    return answer - 1;
}

int main(){
    vector<vector<string>> v = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout<<solution(v)<<endl; // 5
    return 0;
}