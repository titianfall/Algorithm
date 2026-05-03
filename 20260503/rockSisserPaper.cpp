//level 0 - 가위바위보
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    // 가위 2, 바위 0, 보 5
    for(const char ch : rsp){
        if(ch == '2') answer.push_back('0');
        else if(ch == '0') answer.push_back('5');
        else if(ch == '5') answer.push_back('2');
    }
    // map<char, char> table = {{'0', '5'}}
    // for(auto& it : rep) it = table[it]; 
    // 압축
    // for (auto& it : rsp) it = "5-0--2"[it - 48];
                            // loot up table 활용 
                            // it = '0' / it-48 = 0 / "5-0--2" 
    return answer;
}

int main(){
    cout<<solution("2");
    return 0;
}