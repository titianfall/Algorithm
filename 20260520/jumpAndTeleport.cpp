// level 2 - 점프와 순간이동
#include <iostream>
using namespace std;

// 홀수: x2는 항상 짝수를 만드므로 순간이동으로는 도달 불가 → 점프(+1)로만 옴, 건전지 1
// 짝수: 순간이동(x2)으로 오는 게 항상 이득이므로 n/2을 가능한한 많이 사용해야함
int solution(int n)
{
    int ans = 0; // 사용하는 건전지양

    for (n; n > 0; ) {
        if (n % 2 == 1) {
            ans += 1; // 점프로 왔다 → 건전지 1 소비
            n -= 1;
        } else {
            n /= 2;   // 순간이동으로 왔다 → 건전지 소비 없음
        }
    }


    /*
    while(n >0){
        ans += n%2;
        n /=2;
    }
    */
    return ans; // n 위치에 도달하기까지 사용한 건전지 최소량을 구한다.
}

int main(){
    cout<<solution(5)<<endl;
    cout<<solution(6)<<endl;
    cout<<solution(5000)<<endl;
    return 0;
}
