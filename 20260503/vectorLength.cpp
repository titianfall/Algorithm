// level 0 - 배열 원소의 길이
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;

    for(int i = 0; i < strlist.size(); i++) 
        answer.push_back(strlist[i].length());
    return answer;
}

int main(){
    vector<string> v = {"We", "are", "the", "world!"};

    vector<int> lengthV = solution(v);

    for(int it : lengthV){
        cout<<it<<" ";
    }
    // 출력 고민
    return 0;
}