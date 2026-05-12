// level 2 - 다음 큰 숫자
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열 변환 연산이 너무느림
string intToBinary(int num){
    if(num == 0) return "0";
    string result = "";

    while(num > 0){
        result += to_string(num%2);
        num /= 2;
    }
    // 거꾸로 나온다.
    for(int i = 0; i < result.size()/2; i++){
        char tmp = result[i];
        result[i] = result[result.size() - 1 - i];
        result[result.size() - 1 - i] = tmp;
    }
    return result; 
}

int countOnes(int n)
{
    int count = 0;
    while(n > 0){
        //if(n%2 == 1) count++;
        //n/=2;

        count += n & 1;
        n >>= 1;
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    int numCount = countOnes(n);

    answer = n+1;
    while(numCount != countOnes(answer)){
        answer++;
    }
    
    // int num = bitset<20>(n).count():

    // while(bitset<20>(++n).count() != num);
    return answer;
}

int main(){
    cout<<solution(78)<<endl;
    cout<<solution(15)<<endl;
    return 0;
}