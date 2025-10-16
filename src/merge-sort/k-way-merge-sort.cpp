#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr, int l, int r) {
    for (int i = l; i <= r; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>& arr, int l, int m, int r) {
    cout << "Merging subarrays [" << l << "-" << m << "] and [" << m + 1 << "-" << r << "]\n";
    cout << "Left: ";
    printArray(arr, l, m);
    cout << "Right: ";
    printArray(arr, m + 1, r);

    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "Merged: ";
    printArray(arr, l, r);
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }

    int m = l + (r - l) / 2;

    cout << "Splitting array [" << l << "-" << r << "] at " << m << "\n";
    cout << "Left part: ";
    printArray(arr, l, m);
    cout << "Right part: ";
    printArray(arr, m + 1, r);

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    cout << "Initial array: ";
    printArray(arr, 0, arr_size - 1);

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array: ";
    printArray(arr, 0, arr_size - 1);

    return 0;
}


// o(nlogn) time complexity
// o(n) space complexity