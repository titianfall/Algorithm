#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while(i <= j) {
        while(arr[i] < pivot) {
            ++i;
        }

        while(arr[j] > pivot) {
            --j;
        }

        if(i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }

    return i;
}

void quickSort(vector<int>& arr, int left, int right) {
    if(left >= right) return;

    int mid = partition(arr, left, right);

    quickSort(arr, left, mid - 1);
    quickSort(arr, mid, right);
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

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> quickSorted = arr;
    quickSort(quickSorted, 0, n - 1);

    cout << "quickSort: ";
    printVector(quickSorted);

    vector<int> stlSorted = arr;
    sort(stlSorted.begin(), stlSorted.end());

    cout << "std::sort: ";
    printVector(stlSorted);

    return 0;
}

/*
예제 입력
6
8 3 5 1 2 7

예제 출력
quickSort: 1 2 3 5 7 8
std::sort: 1 2 3 5 7 8
*/
