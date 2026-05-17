// level 2 - 피보나치 수
#include <iostream>
#include <iostream>

// 모듈로 연산을 사용한 피보나치 - 메이플의 확률문제가 이것때문에 발생하기도 했다. 비록 오래된 모듈로 연산때문이긴 하지만
// N이 10만이라고 가정하면 수가 폭발적으로 증가한다.
// F(100000) = 사람이 읽을수도 없는 큰 문자다 때문에 연산 중간중간에도 모듈로 연산을 통해 수를 제한해줘야한다. 
int solution(int n) {
    const int MOD = 1234567;
    int a = 0, b = 1;
    for (int i = 1; i < n; i++) {
        int next = (a + b) % MOD;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    std::cout << solution(3) << std::endl;  // 2
    std::cout << solution(5) << std::endl;  // 5
    return 0;
}