# 보글 게임 (BOGGLE)

## 문제 정보

| 항목 | 내용 |
| --- | --- |
| 문제 ID | BOGGLE |
| 시간 제한 | 10000 ms |
| 메모리 제한 | 65536 kb |
| 출제자 | JongMan |
| 출처 | 알고리즘 문제 해결 전략 |
| 분류 | 동적계획법 |

## 문제

보글 게임은 5x5 크기의 알파벳 격자에서 영어 단어를 찾는 게임이다.

단어는 게임판의 한 칸에서 시작해, 펜을 움직이면서 만나는 글자들을 순서대로 이어 붙여 만든다.
펜은 현재 칸에서 상하좌우 또는 대각선으로 인접한 칸으로 이동할 수 있다.

지나간 칸을 다시 지나는 것은 가능하다.
하지만 펜을 이동하지 않고 같은 칸의 글자를 연속해서 여러 번 사용할 수는 없다.

보글 게임판과 단어 목록이 주어질 때, 각 단어를 게임판에서 만들 수 있는지 출력하는 프로그램을 작성하라.

## 입력

첫 줄에는 테스트 케이스의 수 `C`가 주어진다.

각 테스트 케이스는 다음과 같이 주어진다.

- 5줄에 걸쳐 보글 게임판이 주어진다.
- 각 줄은 5개의 알파벳 대문자로 이루어진다.
- 다음 줄에는 단어의 수 `N`이 주어진다.
- 그 다음 `N`줄에는 확인할 단어가 한 줄에 하나씩 주어진다.

제한 조건은 다음과 같다.

- `C <= 50`
- `1 <= N <= 10`
- 각 단어는 알파벳 대문자로만 이루어진다.
- 각 단어의 길이는 1 이상 10 이하이다.

## 출력

각 테스트 케이스마다 `N`줄을 출력한다.

각 줄에는 입력으로 주어진 단어를 먼저 출력하고, 한 칸 띄운 뒤 찾을 수 있으면 `YES`, 찾을 수 없으면 `NO`를 출력한다.

## 예제 입력

```text
1
URLPM
XPRET
GIAET
XTNZY
XOQRS
6
PRETTY
GIRL
REPEAT
KARA
PANDORA
GIAZAPX
```

## 예제 출력

```text
PRETTY YES
GIRL YES
REPEAT YES
KARA NO
PANDORA NO
GIAZAPX YES
```

## 입력 처리 코드

```cpp
int main() {
    int C;
    cin >> C;

    while (C--) {
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
```

위 코드는 문제의 입력 형식 그대로 `cin`으로 받는다.
현재 연습 코드에서는 `board`를 전역 변수로 두었기 때문에 `main()` 안에서 다시 `vector<string> board(5)`를 만들지 않는다.
단어를 찾을 수 있으면 `true`, 없으면 `false`를 반환하는 탐색 함수를 직접 구현하면 된다.

## 풀이 방향

각 단어에 대해 보드의 모든 칸을 시작점으로 탐색한다.

현재 칸의 글자가 단어의 현재 위치 글자와 다르면 실패한다.
현재 글자가 맞고 단어의 마지막 글자까지 확인했다면 성공이다.
아직 남은 글자가 있다면 8방향으로 이동하며 다음 글자를 찾는다.

8방향 이동 배열은 다음처럼 둘 수 있다.

```cpp
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
```

이 배열은 다음 순서로 8칸을 본다.

```text
왼쪽 위    위    오른쪽 위
왼쪽      현재   오른쪽
왼쪽 아래  아래  오른쪽 아래
```

이 문제는 단순 완전탐색만으로는 시간 초과가 날 수 있다.
같은 상태를 반복해서 탐색하지 않도록 메모이제이션을 고려해야 한다.

## 완전탐색으로 다시 풀기

처음 다시 풀 때는 메모이제이션을 넣지 말고 완전탐색 흐름부터 맞춘다.

함수 역할은 두 단계로 나누면 이해하기 쉽다.

```cpp
bool hasWord(int y, int x, const string& word)
```

이 함수는 `y, x` 위치에서 시작해서 `word`를 만들 수 있는지 확인한다.
즉 특정 한 칸에서 출발하는 재귀 함수다.

```cpp
bool findWord(const string& word)
```

이 함수는 보드의 모든 칸을 시작점으로 시도한다.
BOGGLE 입력에는 시작 좌표가 주어지지 않기 때문에, 단어 하나마다 `5x5` 전체를 시작점으로 돌려야 한다.

```cpp
bool findWord(const string& word) {
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (hasWord(y, x, word)) {
                return true;
            }
        }
    }
    return false;
}
```

## 재귀 함수의 기저 조건

`hasWord(y, x, word)`는 아래 순서로 검사한다.

```cpp
if (!inRange(y, x)) return false;
if (board[y][x] != word[0]) return false;
if (word.size() == 1) return true;
```

의미는 다음과 같다.

- 현재 좌표가 보드 밖이면 실패
- 현재 칸의 글자가 찾는 단어의 첫 글자와 다르면 실패
- 첫 글자가 맞고 단어 길이가 1이면 성공

여기까지 통과했다면, 현재 칸에서 `word[0]`은 찾은 것이다.
이제 인접한 8칸에서 나머지 문자열을 찾으면 된다.

## word.substr(1)의 의미

```cpp
hasWord(nextY, nextX, word.substr(1))
```

`word.substr(1)`은 문자열의 1번 인덱스부터 끝까지 잘라낸 새 문자열이다.

```cpp
string word = "PRETTY";
word.substr(1); // "RETTY"
```

현재 칸에서 `P`를 확인했다면, 다음 칸부터는 `"RETTY"`를 찾으면 된다.

흐름은 다음과 같다.

```text
PRETTY  -> 현재 칸에서 P 확인
RETTY   -> 다음 칸에서 R 확인
ETTY    -> 다음 칸에서 E 확인
TTY     -> 다음 칸에서 T 확인
```

다만 `substr()`은 호출할 때마다 새 문자열을 만들기 때문에 완전히 효율적인 방식은 아니다.
나중에 개선할 때는 문자열을 자르지 않고 `index`만 넘기는 방식으로 바꿀 수 있다.

## 자주 한 실수

### 1. 시작 좌표 y, x를 입력받으려고 한 것

BOGGLE 입력에는 시작 좌표가 없다.

따라서 아래처럼 하면 안 된다.

```cpp
cin >> y >> x;
```

대신 단어마다 모든 칸에서 시작해봐야 한다.

### 2. 범위 검사에서 음수를 빼먹은 것

잘못된 형태:

```cpp
if (y > board.size() || x > board[0].size()) return false;
```

고쳐야 하는 형태:

```cpp
bool inRange(int y, int x) {
    return 0 <= y && y < 5 && 0 <= x && x < 5;
}
```

보드 밖은 `5` 이상인 경우만 있는 것이 아니라 `-1`인 경우도 있다.
8방향으로 이동하면 위쪽이나 왼쪽으로 나갈 때 음수가 자주 나온다.

### 3. nextX에 dx가 아니라 dy를 더한 것

잘못된 형태:

```cpp
int nextY = y + dy[direction];
int nextX = x + dy[direction];
```

고쳐야 하는 형태:

```cpp
int nextY = y + dy[direction];
int nextX = x + dx[direction];
```

`y`는 세로 이동이므로 `dy`, `x`는 가로 이동이므로 `dx`를 더한다.

### 4. int&로 받을 필요가 없는 값

처음에는 이렇게 썼다.

```cpp
bool hasWord(int& y, int& x, const string& word)
```

하지만 `y`, `x`는 함수 안에서 원본 값을 바꿀 필요가 없다.
그냥 값으로 받는 편이 더 단순하다.

```cpp
bool hasWord(int y, int x, const string& word)
```

## 메모이제이션은 나중 단계

메모이제이션은 한 번 계산한 결과를 저장해두고, 같은 질문이 다시 나오면 바로 꺼내 쓰는 방식이다.

BOGGLE에서는 이런 질문이 반복된다.

```text
(y, x) 위치에서 word의 index번째 글자부터 끝까지 만들 수 있는가?
```

완전탐색을 먼저 이해한 뒤에는 아래처럼 상태를 저장하는 방식으로 바꿀 수 있다.

```text
cache[y][x][index]
```

처음 목표는 메모이제이션 없이 아래 흐름을 스스로 다시 짜는 것이다.

```text
입력 받기
단어 하나 읽기
모든 칸을 시작점으로 시도하기
현재 칸과 현재 글자 비교하기
남은 글자를 8방향 재귀로 찾기
YES 또는 NO 출력하기
```

그 다음 단계에서 `substr(1)` 대신 `index`를 넘기고, `cache[y][x][index]`를 붙여서 같은 상태를 다시 계산하지 않도록 만든다.
