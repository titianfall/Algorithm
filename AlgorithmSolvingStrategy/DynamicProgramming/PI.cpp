#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

// 3~5자리로 쪼갤 수 없는 경우를 나타내는 값.
// 어떤 분할의 난이도 합보다도 크므로 min()에서 항상 밀려난다.
const int INF = 987654321;

string N;


// N[a..b] 조각의 난이도를 반환한다.
// 여러 규칙에 해당하는 조각은 먼저 검사한 규칙의 난이도를 갖는다.
int classify(int a, int b) {
    // 판단할 조각만 잘라낸다.
    string M = N.substr(a, b - a + 1);

    // 첫 글자만으로 이루어진 문자열과 같으면 모든 숫자가 같다는 뜻이다. 난이도 1
    if(M == string(M.size(), M[0])) return 1;

    // 등차 수열인지 검사한다. 공차는 첫 두 글자의 차이로 잡는다.
    bool progressive = true;
    for(int i = 0; i < (int)M.size() - 1; ++i) {
        if(M[i + 1] - M[i] != M[1] - M[0]) progressive = false;
    }

    // 등차 수열이면서 공차가 1 혹은 -1이면 난이도 2
    if(progressive && abs(M[1] - M[0]) == 1) return 2;

    // 짝수 번째 글자끼리, 홀수 번째 글자끼리 같으면 두 수가 번갈아 등장한다.
    bool alternating = true;
    for(int i = 0; i < (int)M.size(); ++i) {
        if(M[i] != M[i % 2]) alternating = false;
    }

    // 두 수가 번갈아 등장하면 난이도 4
    if(alternating) return 4;

    // 공차가 1도 -1도 아닌 등차 수열은 난이도 5
    if(progressive) return 5;

    // 그 외의 모든 경우는 난이도 10
    return 10;
}

// N의 최대 길이는 10000. 나머지는 off-by-one 방지용 여유분이다.
int cache[10002];
// N[begin..]을 3~5자리 조각으로 끊었을 때 난이도 합의 최솟값을 반환한다.
int memorize(int begin) {
    // 기저 사례: 수열의 끝에 도달했다.
    if(begin == (int)N.size()) return 0;

    // 메모이제이션. 답은 begin에만 의존하므로 상태는 N.size()가지뿐이다.
    int& ret = cache[begin];
    if(ret != -1) return ret;

    // 끝까지 INF로 남으면 이 위치부터는 쪼갤 방법이 없다는 뜻이다.
    ret = INF;
    for(int L = 3; L <= 5; ++L) {
        // 남은 글자가 L개보다 적으면 이 조각은 만들 수 없다.
        if(begin + L > (int)N.size()) break;

        // 뒷부분의 최소 난이도. 쪼갤 수 없으면 INF가 온다.
        int sub = memorize(begin + L);
        if(sub == INF) continue;

        // 이번 조각의 난이도 + 뒷부분의 최소 난이도
        ret = min(ret, classify(begin, begin + L - 1) + sub);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;

    while(count--) {
        cin >> N;

        // 테스트 케이스마다 이전 계산 결과를 지운다.
        memset(cache, -1, sizeof(cache));

        cout << memorize(0) << '\n';
    }

    return 0;
}
