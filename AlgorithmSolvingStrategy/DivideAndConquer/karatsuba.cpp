#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 각 숫자는 1의 자리부터 거꾸로 저장한다.
// 예: 1234 -> {4, 3, 2, 1}

void normalize(vector<int>& num) {
    num.push_back(0);

    int size = static_cast<int>(num.size());

    for(int i = 0; i + 1 < size; ++i) {
        if(num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }

    while(num.size() > 1 && num.back() == 0) {
        num.pop_back();
    }
}

// a += b * 10^k
void addTo(vector<int>& a, const vector<int>& b, int k) {
    if(a.size() < b.size() + k) {
        a.resize(b.size() + k, 0);
    }

    int bSize = static_cast<int>(b.size());

    for(int i = 0; i < bSize; ++i) {
        a[i + k] += b[i];
    }

    normalize(a);
}

// a -= b
// a >= b라고 가정한다.
void subFrom(vector<int>& a, const vector<int>& b) {
    if(a.size() < b.size()) {
        a.resize(b.size(), 0);
    }

    int bSize = static_cast<int>(b.size());

    for(int i = 0; i < bSize; ++i) {
        a[i] -= b[i];
    }

    normalize(a);
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    if(a.empty() || b.empty()) return vector<int>();

    vector<int> result(a.size() + b.size() + 1, 0);
    int aSize = static_cast<int>(a.size());
    int bSize = static_cast<int>(b.size());

    for(int i = 0; i < aSize; ++i) {
        for(int j = 0; j < bSize; ++j) {
            result[i + j] += a[i] * b[j];
        }
    }

    normalize(result);
    return result;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size();
    int bn = b.size();

    if(an < bn) return karatsuba(b, a);
    if(an == 0 || bn == 0) return vector<int>();

    // 작은 입력은 단순 곱셈이 더 빠르고 코드도 안정적이다.
    if(an <= 50 || bn <= 50) return multiply(a, b);

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    // z0 = a0 * b0
    vector<int> z0 = karatsuba(a0, b0);

    // z2 = a1 * b1
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

    normalize(result);
    return result;
}

vector<int> toDigits(const string& number) {
    vector<int> digits;
    int length = static_cast<int>(number.size());

    for(int i = length - 1; i >= 0; --i) {
        digits.push_back(number[i] - '0');
    }

    normalize(digits);
    return digits;
}

void printNumber(const vector<int>& number) {
    if(number.empty()) {
        cout << 0;
        return;
    }

    for(auto it = number.rbegin(); it != number.rend(); ++it) {
        cout << *it;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string first;
    string second;

    cin >> first >> second;

    vector<int> a = toDigits(first);
    vector<int> b = toDigits(second);
    vector<int> result = karatsuba(a, b);

    printNumber(result);
    cout << '\n';

    return 0;
}

/*
예제 입력
1234 5678

예제 출력
7006652
*/
