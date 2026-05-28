// level 2 - 영어 끝말잇기
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words){
    unordered_set<string> used;
    used.insert(words[0]);

    for(int i = 1; i < words.size(); i++){
        string& prev = words[i - 1];
        string& cur = words[i];

        if(prev.back() != cur.front() || used.count(cur)){
            return { i % n + 1, i / n + 1};
        }
    }
    return {0, 0};
}

int main(){
    vector<int> v = solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
    // 3, 3
    for(int it : v) cout<<it<<" ";
    return 0;
}
