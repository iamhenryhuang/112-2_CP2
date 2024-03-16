#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int middle, int right) {
    int left_size = middle - left + 1; 
    int right_size = right - middle;

    vector<int> L_temp(left_size), R_temp(right_size);

    for (int i = 0; i < left_size; i++) {
        L_temp[i] = arr[left + i];
    }

    for (int j = 0; j < right_size; j++) {
        R_temp[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0;
    int k = left; // Initial index of merged subarray
    while (i < left_size && j < right_size) {
        if (L_temp[i] <= R_temp[j]) {
            arr[k] = L_temp[i];
            i++;
        } else {
            arr[k] = R_temp[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = L_temp[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = R_temp[j];
        j++;
        k++;
    }
}

void mergeSlice(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSlice(arr, left, middle); // left sub-array
    mergeSlice(arr, middle + 1, right); // right sub-array
    merge(arr, left, middle, right);
}

int main() {
    int totalNum, elementNum;
    cin >> totalNum;
    vector<int> element;
    for (int i = 0; i < totalNum; i++) {
        cin >> elementNum;
        for (int k = 0; k < elementNum; k++) {
            int input;
            cin >> input;
            element.push_back(input);
        }
    }

    mergeSlice(element, 0, element.size() - 1);

    for (int i = 0; i < element.size(); i++) {
        cout << element[i] << " ";
    }

    return 0;
}
