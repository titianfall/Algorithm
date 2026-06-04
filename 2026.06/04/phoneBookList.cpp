// level 2 - 전화번호 목록
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 시간복잡도 : O(N log N * L(문자열 길이))
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end()); // O(n log n)

    // 정렬하면 접두어 관계인 전화번호는 서로 이웃하게 됩니다.
    for(size_t i = 0; i < phone_book.size() - 1; i++) {
        const string& phone = phone_book[i];
        const string& nextPhone = phone_book[i + 1];

        // O(N * L)
        if(nextPhone.compare(0, phone.size(), phone) == 0) return false;
    }

    return true;
}

// O(n*2 * 문자열 길이(20)) 최악 = 1조 * 20 = 20000초
// 모든 전화번호를 서로 비교하는 풀이로, 큰 입력에서는 시간 초과가 발생합니다.
bool solution2(vector<string> phone_book) {
    bool answer = true;

    // 접두어가 있는지 확인하며 있을 경우 false를 리턴 아닐 경우 true를 리턴합니다.
    for(const string& phone : phone_book) {
        for(const string& tmp : phone_book) {
            // 접두어가 되는 단어보다 짧거나, 동일한 단어일 경우
            if(tmp.size() < phone.size() || phone == tmp) continue;

            // 접두어보다 긴 단어들에 대해서만 실행
            bool isPrefix = true;
            for(size_t i = 0; i < phone.size(); i++){
                if(phone[i] != tmp[i]) {
                    isPrefix = false;
                    break;
                }
            }
            if(isPrefix) return false;
        }
    }

    return answer;
}

int main(){
    cout<<solution({"119", "97674223", "1195524421"})<<endl;
    cout<<solution({"123","456","789"})<<endl;
    cout<<solution({"12", "123", "1235", "567", "88"})<<endl;
    return 0;
}
