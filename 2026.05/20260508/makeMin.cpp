// level 2 - 최솟값 만들기 
// 배열 A, B에서 각각 한 개의 숫자를 뽑아 두 수를 곱하여 누적된 값이 최소가 되도록 만든다. 
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// 퀵정렬 - pivot은 배열의 마지막 값으로 설정
int partition(vector<int>& arr, int low, int high) {                                                                                              
    int pivot = arr[high]; // 피봇 설정
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 분할 
        int pi = partition(arr, low, high);

        // 정복
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end()); 
    sort(B.rbegin(), B.rend());

    for(int i = 0; i < A.size(); i++){
       answer += A[i] * B[i];
    }
    return answer;
}

int main(){
    cout<<solution({1, 4, 2}, {5, 4, 4});
    return 0;
}