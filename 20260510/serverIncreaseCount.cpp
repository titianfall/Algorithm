#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int count = 0;
    int server = 0;  // 시작은 증설된 서버 0대
    vector<int> added(players.size(), 0);

    for(int i = 0; i < players.size(); i++){
        if(i >= k){
            server -= added[i - k];  // k시간 전에 증설한 서버 반납
        }

        // 필요한 서버 수 = floor(players[i] / m)
        int needed = players[i] / m - server;
        if(needed > 0){
            server += needed;
            count += needed;
            added[i] = needed;
        }
    }
    return count;
}
int main() {
    cout << solution({0,2,3,3,1,2,0,0,0,0,4,2,0,6,0,4,2,13,3,5,10,0,1,5}, 3, 5) << "\n"; // 7
    cout << solution({0,0,0,10,0,12,0,15,0,1,0,1,0,0,0,5,0,0,11,0,8,0,0,0}, 5, 1) << "\n"; // 11
    cout << solution({0,0,0,0,0,2,0,0,0,1,0,5,0,2,0,1,0,0,0,0,0,0,0,1}, 1, 1) << "\n";    // 12
    return 0;
}