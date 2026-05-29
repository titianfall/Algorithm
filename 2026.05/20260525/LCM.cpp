// level 2 - n개의 최소공배수(Least Common Multiple)
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(vector<int> arr) {
    int answer = 0;
    
    int tmp;
    int i = 1;
    while(true){
        tmp = (arr[arr.size() - 1] * (i++));
        bool isLCM = true;
        for(int i = 0; i < arr.size(); i++){
            if(tmp % arr[i] != 0) isLCM = false;
        }
        if(isLCM){
            answer = tmp;
            break;
        }
    }
    return answer;
}

int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
int lcm(int x, int y) { return x * y / gcd(x, y); }
int solution2(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);
    return answer;
}

int main(){
    cout<<solution({2, 6, 8 ,14})<<endl;
    cout<<solution({1, 2, 3})<<endl;
    return 0;
}