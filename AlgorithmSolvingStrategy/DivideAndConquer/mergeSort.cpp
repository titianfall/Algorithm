#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    if(left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
}

void printVector(const vector<int>& arr) {
    for(int value : arr) {
        cout << value << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> temp(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    mergeSort(arr, temp, 0, n - 1);

    cout << "mergeSort: ";
    printVector(arr);

    vector<int> leftPart = {1, 3, 8};
    vector<int> rightPart = {2, 5, 7};
    vector<int> merged(leftPart.size() + rightPart.size());

    std::merge(
        leftPart.begin(), leftPart.end(),
        rightPart.begin(), rightPart.end(),
        merged.begin()
    );

    cout << "std::merge: ";
    printVector(merged);

    return 0;
}

/*
예제 입력
6
8 3 5 1 2 7

예제 출력
mergeSort: 1 2 3 5 7 8
std::merge: 1 2 3 5 7 8
*/
