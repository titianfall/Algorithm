#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. 무식하게 풀기
int allHugCount(const string& members, const string& fans) {
    int hugCount = 0; // 허그 횟수
    int N = members.length();
    int M = fans.length();

    // 모든 멤버가 팬과 마주보는 시점만 순회한다.
    for(int i = 0; i <= M - N; ++i) {
        bool ok = true;
        for(int j = 0; j < N; ++j) {
            // 남성 멤버가 남성 팬과 만나면 악수이므로 실패
            if(members[j] == 'M' && fans[i + j] == 'M') {
                ok = false;
                break;
            }
        }
        if(ok) hugCount++;
    }
    return hugCount;
}

// 2. 곱셈으로의 변형 (fanmeeting.md)
//
// 이 문제에서 C[i]는 "i번 시점에 악수한 남남 쌍의 수"를 그대로 담고 있어야 한다.
// 따라서 자리 올림을 하는 normalize()는 사용하지 않는다.
// 각 자리를 0과 9 사이로 맞추는 순간 쌍의 개수가 뭉개지기 때문이다.

// a += b * 10^k (자리 올림 없음)
void addTo(vector<int>& a, const vector<int>& b, int k) {
    if(a.size() < b.size() + k) {
        a.resize(b.size() + k, 0);
    }

    int bSize = static_cast<int>(b.size());

    for(int i = 0; i < bSize; ++i) {
        a[i + k] += b[i];
    }
}

// a -= b (자리 올림 없음)
void subFrom(vector<int>& a, const vector<int>& b) {
    if(a.size() < b.size()) {
        a.resize(b.size(), 0);
    }

    int bSize = static_cast<int>(b.size());

    for(int i = 0; i < bSize; ++i) {
        a[i] -= b[i];
    }
}

// 입력이 작을 때 쓰는 단순 곱셈
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    if(a.empty() || b.empty()) return vector<int>();

    vector<int> result(a.size() + b.size() - 1, 0);
    int aSize = static_cast<int>(a.size());
    int bSize = static_cast<int>(b.size());

    for(int i = 0; i < aSize; ++i) {
        for(int j = 0; j < bSize; ++j) {
            result[i + j] += a[i] * b[j];
        }
    }

    return result;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();

    // 항상 a가 더 길도록 맞춘다.
    if(an < bn) return karatsuba(b, a);

    if(an == 0 || bn == 0) return vector<int>();

    // 작은 입력은 단순 곱셈이 더 빠르다.
    if(an <= 50) return multiply(a, b);

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
    vector<int> b1(b.begin() + min<int>(bn, half), b.end());

    // z0 = a0 * b0 (아랫자리)
    vector<int> z0 = karatsuba(a0, b0);
    // z2 = a1 * b1 (윗자리)
    vector<int> z2 = karatsuba(a1, b1);

    // z1 = (a0 + a1) * (b0 + b1) - z0 - z2
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    // result = z0 + z1 * 10^half + z2 * 10^(2 * half)
    vector<int> result;
    addTo(result, z0, 0);
    addTo(result, z1, half);
    addTo(result, z2, half + half);

    return result;
}

int hugs(const string& members, const string& fans) {
    int N = members.size(), M = fans.size();

    // 남성을 1, 여성을 0으로 둔다. 두 값의 곱이 1이면 남남 쌍, 즉 악수다.
    vector<int> A(N), B(M);
    for(int i = 0; i < N; ++i) A[i] = (members[i] == 'M');

    // 팬은 뒤집어서 저장한다. 그래야 곱셈의 각 자리가 한 시점과 대응된다.
    for(int i = 0; i < M; ++i) B[M - i - 1] = (fans[i] == 'M');

    // C[i]는 해당 시점에 악수한 남남 쌍의 수가 된다.
    vector<int> C = karatsuba(A, B);

    // 모든 멤버가 팬과 마주 보는 시점은 i가 N - 1부터 M - 1까지다.
    int allHugs = 0;
    for(int i = N - 1; i < M; ++i) {
        if(C[i] == 0) ++allHugs;
    }
    return allHugs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int count;
    cin >> count;

    while(count--) {
        string members;
        cin >> members;

        string fans;
        cin >> fans;

        int result = hugs(members, fans);

        cout << result << '\n'; // 모든 멤버가 동시에 포옹하는 횟수 출력
    }
    
    return 0;
}