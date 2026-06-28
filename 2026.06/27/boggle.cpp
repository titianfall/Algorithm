#include <iostream>
#include <vector>
#define DIRECTION_SIZE 8
using namespace std;

vector<string> board(5);
int dy[DIRECTION_SIZE] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[DIRECTION_SIZE] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool inRange(int y, int x){
   return 0 <= y && y < 5 && 0 <= x && x < 5;
}

bool hasWord(int y, int x, const string& word){
    // 기저 1: 시작 위치가 범위 내인지 확인
    if(!inRange(y, x)) return false; // 범위 외부
    // 기저 2: 첫 글자가 일치하지 않으면 실패
    if(board[y][x] != word[0]) return false;
    // 기저 3: 단어의 길이가 1이면 무조건 성공
    if(word.size() == 1) return true;

    // 인접 8칸을 검사한다.
    for(int direction = 0; direction < DIRECTION_SIZE; ++direction){
        int nextY = y + dy[direction];
        int nextX = x + dx[direction];

        // 다음 칸이 범위에 있는지, 첫 글자는 일치하는지 확인할 필요는 없다.
        if(hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}

bool findWord(const string& word){
    for(int y = 0; y < 5; ++y){
        for(int x = 0; x < 5; ++x){
            if(hasWord(y, x, word))
                return true;
        }
    }
    return false;
}
// 최악의 경우를 예로 들어보면 AAAAAAAH 라는 단어를 A만으로 가득찬 격자에서 실행한다.
// 모든 경우의 수를 탐색한후 없다고 반환하므로 O(8^n-1) 수준으로 탐색을 한다.
// 시간복잡도가 O(8^n) 이다. 
// 단어의 길이가 짧아야만 완전 탐색으로 해결이 가능하다.


int main() {
    int n;
    cin >> n;

    while (n--) {
        for (int i = 0; i < 5; ++i) {
            cin >> board[i];
        }

        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            string word;
            cin >> word;
            
            cout << word << " " << (findWord(word) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
