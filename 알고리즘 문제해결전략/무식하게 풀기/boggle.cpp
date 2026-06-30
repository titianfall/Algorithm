#include <iostream>
#include <string>
#include <vector>

#define DIRECTION_SIZE 8
using namespace std;

bool inRange(int y, int x){
    return (0 <= y && y < 5 && 0 <= x && x < 5);
} 

// 찾고자 하는 단어를 가졌는지 실제로 검사하는 함수
bool hasWord(int y, int x, const string& word, const vector<string>& board){
    // 탐색 방향 설정 현재 위치 기준 8방향 미리 배열로 선언
    // 현재 칸을 중심으로 한 3 x 3 영역에서 왼쪽 위부터 오른쪽 아래 순서로 확인한다.
    int dy[DIRECTION_SIZE] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dx[DIRECTION_SIZE] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // 기저 조건 설정
    // 기저 1 - 좌표가 범위 내인지?
    if(!inRange(y, x)) return false;
    // 기저 2 - 찾고자 하는 글자가 보드의 글자와 일치하는지?
    if(board[y][x] != word[0]) return false;
    // 기저 3 - 단어의 길이가 1이면 무조건 성공
    // (기저를 통과함에 따른 + 답을 곧장 반환하는 기저 사례이다)
    if(word.size() == 1) return true;

    // 인접 8칸을 조사한다.
    for(int direction = 0; direction < DIRECTION_SIZE; ++direction){
        int nextY = y + dy[direction];
        int nextX = x + dx[direction];

        // 재귀 호출 사용
        if(hasWord(nextY, nextX, word.substr(1), board)) return true;
    }

    return false;
}

// 시간복잡도: O(8^n) — n은 단어 길이
// 최악의 경우: 'AAAAAAAH' 단어를 A만으로 가득 찬 격자에서 탐색
// 매 칸에서 8방향으로 재귀 호출하며 끝까지 탐색 후 실패를 반환하므로
// 단어 길이가 짧아야만 완전 탐색으로 해결 가능하다.

// 찾고자 하는 단어를 가졌는지 검사하는 함수
bool findWord(const string& word, const vector<string>& board){
    for(int y = 0; y < 5; ++y){
        for(int x = 0; x < 5; ++x){
            if(hasWord(y, x, word, board)) return true;
        }
    }

    // 찾고자 하는 단어가 없음
    return false;
}
int main(){
    int count;
    cin >> count;

    while(count--){
        vector<string> board(5);
        for(int i = 0; i < 5; ++i){
            cin >> board[i];
        }
        
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            string word;
            cin >> word;

            cout << word << " " << (findWord(word, board) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
