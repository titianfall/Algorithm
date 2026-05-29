// level 2 연습문제 - 귤 고르기
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int sizeCount = 0;
    map<int, int> size;
    // 선택하는 귤의 수는 k개 이다.

    // 1. 처음에는 1, (1, 2) 이럭식으로 제외하려 했으나 구현이 복잡하고 별로다.

    // 2. map을 사용해서 숫자가 나오는 횟수를 count하고 
    // 1, (1, 2) 이렇게 제외하는 방식을 사용하며 k번째에서 멈추는 방법으로 전환

    // 3. 그냥 빈도가 높은 것들의 순서를 신경쓰지 않고 가능한 적은 개수로 k개를 만족하는지만 확인하면 된다.
    int n = tangerine.size(); // 수확하는 귤의 수는 8개 이다.
    for(int i = 0; i < n; i++) size[tangerine[i]]++;
    
    vector<int> tangerineSize;
    for(auto& it : size){
        tangerineSize.push_back(it.second);
    }

    sort(size.rbegin(), size.rend());

    int total = 0;
    
    for(int cnt : tangerineSize) {
        total += cnt;
        answer++;
        if(total >= k) break;
    }
    // 선택하는 귤의 크기 종류가 가장 적은 개수를 리턴함
    return answer;
}

int main(){
    cout<<solution(6, {1, 3, 2, 5, 4, 5, 2, 3})<<endl;
    cout<<solution(4, {1, 3, 2, 5, 4, 5, 2, 3})<<endl;
    cout<<solution(2, {1, 1, 1, 1, 2, 2, 2, 3})<<endl;
    return 0;
}