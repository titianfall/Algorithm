#include <iostream>
#include <vector>

using namespace std;

// 두 큰 수를 곱하는 O(n*2)시간 알고리즘

// num[]의 자릿수 올림을 처리한다.
void normalize(vector<int>& num) {
    num.push_back(0);

    // 자릿수 올림을 처리한다.
    for (int i = 0; i + 1 < num.size(); ++i) {
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
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}
// 두 긴 자연수의 곱을 반환한다. 
// 각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j]; // 각 자리수의 곱셈을 올림 없이 그대로 합산만 하여 저장
        }
    }

    normalize(c);
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {3, 2, 1}; // 123
    vector<int> b = {6, 5, 4}; // 456
    vector<int> result = multiply(a, b); // 123 * 456

    for(vector<int>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it){
        cout << *it << " ";
    }
    return 0;
}
