# 쿼드 트리 뒤집기 (QUADTREE)

- 출처: [Algospot QUADTREE](https://algospot.com/judge/problem/read/QUADTREE)
- 분류: 분할 정복
- 시간 제한: 10,000 ms
- 메모리 제한: 65,536 KB

<details>
<summary>문제 설명</summary>

<br>

흑백 그림을 쿼드 트리 문자열로 압축한 결과가 주어진다. 이 그림을 **상하로 뒤집은 뒤**, 다시 쿼드 트리 문자열로 출력한다.

쿼드 트리는 `2^N × 2^N` 크기의 흑백 그림을 다음 규칙으로 표현한다.

- 영역 전체가 검은색이면 `b`
- 영역 전체가 흰색이면 `w`
- 한 색으로만 이루어지지 않았다면 `x` 뒤에 네 부분의 결과를 붙인다.

`x` 뒤의 네 부분은 항상 다음 순서다.

```text
왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래
```

상하 반전에서는 위쪽 두 영역과 아래쪽 두 영역의 위치가 서로 바뀐다. 따라서 `x` 노드의 자식 결과가 `UL, UR, LL, LR`라면, 뒤집은 결과는 다음 순서로 조합한다.

```text
x + LL + LR + UL + UR
```

## 입력

첫 줄에 테스트 케이스 수 `C`가 주어진다. (`C ≤ 50`)

이후 `C`개의 줄에 쿼드 트리로 압축된 문자열이 하나씩 주어진다.

- 각 문자열의 길이: 최대 1,000
- 원본 그림의 크기: 최대 `2^20 × 2^20`

## 출력

각 테스트 케이스마다 상하로 뒤집은 그림의 쿼드 트리 압축 결과를 한 줄에 출력한다.

## 예제 입력

```text
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
```

## 예제 출력

```text
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
```

</details>

## 쿼드 트리 문자열 읽는 순서

쿼드 트리의 노드는 다음 규칙을 가진다.

```text
노드 = b | w | x + 노드 4개
```

- `b`: 현재 영역 전체가 검은색인 리프 노드
- `w`: 현재 영역 전체가 흰색인 리프 노드
- `x`: 현재 영역을 네 부분으로 나누는 내부 노드

`x` 뒤의 자식은 언제나 `왼쪽 위(UL)`, `오른쪽 위(UR)`, `왼쪽 아래(LL)`, `오른쪽 아래(LR)` 순서다.

상하 반전 후에는 자식 순서가 다음처럼 바뀐다.

```text
x + UL + UR + LL + LR
↓
x + LL + LR + UL + UR
```

## 1. 압축 문자열 분할하기

문자열에서 각 사분면이 차지하는 길이를 먼저 구하고, `substr()`로 네 조각을 나누는 방식이다.

예를 들어 `xbwxwbbwb`는 다음처럼 분할된다.

```text
x | b | w | xwbbw | b
    UL  UR    LL    LR
```

여기서 `LL`의 `xwbbw`는 내부에 다시 `x`가 있으므로, 단순히 다음 `x`가 나올 때까지 읽어서는 안 된다. `b`, `w`, `x + 자식 4개` 규칙으로 **노드 하나가 끝나는 위치**를 재귀적으로 찾아야 한다.

```cpp
// start 위치에서 시작하는 쿼드 트리 노드 하나의 문자열 길이를 반환한다.
int getLength(const string& quad, int start) {
    // 기저 사례: b 또는 w는 한 글자로 끝나는 리프 노드다.
    if(quad[start] == 'b' || quad[start] == 'w') {
        return 1;
    }

    // x는 자기 자신과 자식 노드 네 개로 구성된다.
    int length = 1;
    for(int i = 0; i < 4; ++i) {
        length += getLength(quad, start + length);
    }

    return length;
}

string flipBySplit(const string& quad) {
    // 기저 사례: 한 색으로만 이루어진 영역은 뒤집어도 같다.
    if(quad[0] == 'b' || quad[0] == 'w') {
        return quad;
    }

    // x 다음에서부터 네 사분면 문자열을 차례대로 분할한다.
    int index = 1;

    int upperLeftLength = getLength(quad, index);
    string upperLeft = quad.substr(index, upperLeftLength);
    index += upperLeftLength;

    int upperRightLength = getLength(quad, index);
    string upperRight = quad.substr(index, upperRightLength);
    index += upperRightLength;

    int lowerLeftLength = getLength(quad, index);
    string lowerLeft = quad.substr(index, lowerLeftLength);
    index += lowerLeftLength;

    int lowerRightLength = getLength(quad, index);
    string lowerRight = quad.substr(index, lowerRightLength);

    // 각각 위와 아래 조각들의 위치를 바꾼다.
    return "x" + flipBySplit(lowerLeft) + flipBySplit(lowerRight)
        + flipBySplit(upperLeft) + flipBySplit(upperRight);
}
```

### 시간복잡도

압축 문자열 길이를 `n`, 쿼드 트리의 최대 깊이를 `h`라고 하자.

- `getLength()`는 호출된 부분 문자열을 끝까지 훑는다.
- `flipBySplit()`은 각 내부 노드에서 자식 길이를 구하고, 이후 자식에서 다시 같은 과정을 반복한다.
- 따라서 같은 문자가 조상 노드의 길이 계산에서 여러 번 읽힐 수 있다.

```text
시간복잡도: O(nh)
균형 잡힌 트리: h = O(log n) -> O(n log n)
한쪽으로 깊게 이어진 트리: h = O(n) -> 최악 O(n^2)
```

`substr()`가 문자열을 복사하는 비용도 있으므로, 이 방식은 구조를 이해하기에는 좋지만 가장 효율적인 방법은 아니다.

## 2. 실제 그림을 만들지 않고 뒤집기

### 2-1. `decompressed` 배열과 `decompress()`

`decompress()`는 압축 문자열을 실제 흑백 그림 배열로 펼치는 학습용 함수다. `x`를 만나면 영역을 네 부분으로 나누고, `b` 또는 `w`를 만나면 해당 영역의 모든 칸을 같은 문자로 채운다.

```cpp
// 학습용 압축 해제 배열: 이 문제의 정답 풀이에서는 사용하지 않는다.
constexpr int MAX_SIZE = 1024;
char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator& it, int y, int x, int size) {
    // 현재 노드를 읽고, 다음 문자로 반복자를 옮긴다.
    char head = *(it++);

    // 기저 사례: 한 색으로만 이루어진 영역은 모든 칸을 같은 색으로 채운다.
    if(head == 'b' || head == 'w') {
        for(int dy = 0; dy < size; ++dy) {
            for(int dx = 0; dx < size; ++dx) {
                decompressed[y + dy][x + dx] = head;
            }
        }
        return;
    }

    // x이면 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순서로 압축 해제한다.
    int half = size / 2;
    decompress(it, y, x, half);
    decompress(it, y, x + half, half);
    decompress(it, y + half, x, half);
    decompress(it, y + half, x + half, half);
}
```

이 방법으로 문제를 해결하려면 배열을 상하 반전한 뒤, 배열을 다시 쿼드 트리 문자열로 압축하는 함수도 추가로 필요하다.

압축 해제 자체는 그림 한 칸마다 한 번씩 채우므로 원본 그림의 한 변 길이를 `S`라 할 때 `O(S^2)` 시간과 `O(S^2)` 메모리를 사용한다. 이 문제의 원본 그림 크기는 최대 `2^20 × 2^20`이므로 실제 그림을 만들면 메모리 제한을 넘는다.

### 2-2. 개선: `reverse()`로 바로 뒤집기

배열을 만들지 않고 문자열을 읽는 순간 바로 뒤집은 문자열을 반환한다. 반복자는 이미 읽은 위치를 기억하므로, 각 노드를 한 번만 읽을 수 있다.

```cpp
// 현재 노드를 뒤집은 쿼드 트리 문자열로 반환한다.
string reverse(string::iterator& it) {
    // 현재 노드를 읽고, 다음 문자로 반복자를 옮긴다.
    char head = *(it++);

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
    return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}
```

호출은 다음처럼 한다.

```cpp
auto it = quad.begin();
cout << reverse(it) << '\n';
```

### 시간복잡도

- 반복자는 재귀 호출 전체에서 앞으로만 이동한다.
- 압축 문자열의 각 문자를 정확히 한 번 읽는다.
- 따라서 문자열 길이를 `n`이라 할 때 파싱 과정의 시간복잡도는 `O(n)`이다.
- 재귀 호출 스택은 트리 깊이만큼 사용하므로 추가 메모리는 `O(h)`이다.

반환 문자열 자체는 길이 `n`이므로 출력 결과를 포함하면 `O(n)` 메모리가 필요하다. C++의 문자열 이어 붙이기는 중간 문자열 복사 비용이 생길 수 있지만, 이 문제의 문자열 길이는 최대 1,000이므로 충분하다. 큰 입력까지 엄밀하게 선형 시간을 보장하려면 결과 문자열 버퍼에 `append()`하는 방식으로 작성할 수 있다.

문자열의 각 문자를 한 번씩만 읽으므로 시간복잡도는 문자열 길이를 `n`이라 할 때 `O(n)`이다. 재귀 호출 깊이는 쿼드 트리의 최대 깊이에 비례한다.
