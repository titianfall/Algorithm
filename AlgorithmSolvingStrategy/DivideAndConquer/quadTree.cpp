#include <iostream>
#include <string>

using namespace std;

// 학습용 압축 해제 배열: 이 문제의 정답 풀이에서는 사용하지 않는다.
constexpr int MAX_SIZE = 1024;
char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator& it, int y, int x, int size) {
    // 현재 노드를 읽고, 다음 문자로 반복자를 옮긴다.
    char head = *(it++);

    // 한 색으로만 이루어진 영역은 size x size 칸을 모두 채운다.
    if(head == 'b' || head == 'w') {
        for(int dy = 0; dy < size; ++dy) {
            for(int dx = 0; dx < size; ++dx) {
                decompressed[y + dy][x + dx] = head;
            }
        }
        return;
    }

    // x이면 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순서로 재귀 호출한다.
    int half = size / 2;
    decompress(it, y, x, half);
    decompress(it, y, x + half, half);
    decompress(it, y + half, x, half);
    decompress(it, y + half, x + half, half);
}

// 현재 노드를 뒤집은 쿼드 트리 문자열로 반환한다.
string reverse(string::iterator& it) {
    // 현재 노드를 읽고, 다음 문자로 반복자를 옮긴다.
    char head = *it;
    ++it;

    // 기저 사례: 한 색으로만 이루어진 영역은 뒤집어도 같다.
    if(head == 'b' || head == 'w') {
        return string(1, head);
    }

    // x이면 네 사분면을 원래 순서대로 끝까지 읽는다.
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    // 각각 위와 아래 조각들의 위치를 바꾼다.
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    while(count--){
        string quad;
        cin >> quad;

        auto it = quad.begin();
        cout << reverse(it) << '\n';
    }
    return 0;
}
