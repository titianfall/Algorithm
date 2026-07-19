#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
// 와일드 카드를 활용한 파일 탐색에 대한 문제
// 특수문자인 ? 와 *에 대해 생객해보아야하며

// 와일드 카드 w가 원문 s에 대응되는지 여부를 반환하는 함수 match(w, s)
bool match(const string& w, const string& s) {
    // w[pos] 와 s[pos]를 맞춰나간다.
    int pos = 0;

    // 1. s[pos] != w[pos]
    // 2. w 의 끝에 도달
    // 3. s 의 끝에 도달
    // 4. w[pos]가 *인 경우이다. w 이후의 경우를 패턴 w', s의 pos + skip이후를 문자열 s'으로 하여
    // match(w', s')중 답이 하나라도 참이면 답은 참이된다.
    while(pos < s.size() && pos < w.size() &&
            (w[pos] == '?' || w[pos] == s[pos]))
        ++pos;

    // 더이상 대응될 수 없으면 왜 while문이 끝났는지 확인한다.
    // 2. 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응된다.
    if(pos == w.size()) return pos == s.size();

    // 4. *를 만나서 끝난 경우: * 에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
    if(w[pos] == '*') {
        for(int skip = 0; pos + skip <= s.size(); ++skip) {
            if(match(w.substr(pos + 1), s.substr(pos + skip)))
                return true;
        }
    }

    // 1. 글자가 불일치하거나 3. 문자열만 끝난 경우: 모두 대응되지 않는다.
    return false;
}

int cache[101][101];
// 와일드카드 패턴과 문자열
string W, S;
// match()를 메모이제이션으로 옮긴 함수. w, s는 각각 W와 S에서 비교를 시작할 위치
bool matchMemoized(int w, int s) {
    // 메모이제이션: 이미 계산한 (w, s)라면 저장해 둔 값을 곧장 반환한다.
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    // ? 이거나 같은 글자인 동안 W[w] 와 S[s]를 함께 전진시킨다.
    while(s < S.size() && w < W.size() &&
        (W[w] == '?' || W[w] == S[s])) {
            ++w;
            ++s;
        }

    // 2. 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응된다.
    if(w == W.size()) return ret = (s == S.size());

    // 4. *를 만나서 끝난 경우: * 에 몇 글자를 대응할지 재귀 호출로 확인한다.
    if(W[w] == '*') {
        // skip = 0(빈 문자열)부터 남은 문자열 전체(s + skip == S.size())까지 대응시켜 본다.
        for(int skip = 0; s + skip <= S.size(); ++skip) {
            if(matchMemoized(w + 1, s + skip))
                return ret = 1;
        }
    }

    // 1. 글자가 불일치하거나 3. 문자열만 끝난 경우: 모두 대응 실패
    return ret = 0;
}

int cache2[101][101];
// 다른 분해 방법: *를 for문 대신 두 갈래 재귀로 쪼개 O(n^2)에 푼다.
// 한 부분 문제를 O(1)에 처리하므로 전체가 (부분 문제 수) x O(1) = O(n^2)이 된다.
bool matchMemoized2(int w, int s) {
    // 메모이제이션
    int& ret = cache2[w][s];
    if(ret != -1) return ret;

    // 1. W[w] 와 S[s]가 한 글자로 대응되는 경우(? 이거나 같은 글자): 둘 다 한 칸 전진
    if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
        return ret = matchMemoized2(w + 1, s + 1);

    // 2. 패턴 끝에 도달한 경우: 문자열도 끝났어야 대응된다.
    if(w == W.size()) return ret = (s == S.size());

    // 4. W[w]가 *인 경우: 아래 두 가지로 쪼개서 하나라도 참이면 참
    //    - *가 빈 문자열에 대응 -> 패턴만 한 칸 전진: matchMemoized2(w + 1, s)
    //    - *가 한 글자 이상에 대응 -> 문자열만 한 칸 전진: matchMemoized2(w, s + 1)
    if(W[w] == '*')
        if(matchMemoized2(w + 1, s) ||
           (s < S.size() && matchMemoized2(w, s + 1)))
            return ret = 1;

    // 3. 그 외(글자 불일치 / 문자열만 끝남): 모두 대응 실패
    return ret = 0;
}

// 입력
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;
    while(count--) {
        // 패턴 W를 입력받는다.
        cin >> W;

        cin >> n;
        // 대응되는 파일명을 모아 두었다가 사전순으로 출력할 벡터
        vector<string> matched;
        for(int i = 0; i < n; ++i) {
            // 파일명 S를 입력받는다.
            cin >> S;
            // S가 바뀔 때마다 캐시를 초기화한 뒤 대응 여부를 확인한다.
            memset(cache, -1, sizeof(cache));
            if(matchMemoized(0, 0))
                matched.push_back(S);
        }

        // 사전순으로 정렬해 한 줄에 하나씩 출력한다.
        sort(matched.begin(), matched.end());
        for(const string& file : matched)
            cout << file << '\n';
    }

    return 0;
}
