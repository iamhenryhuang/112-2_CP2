#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using reference
void bubbleSort(vector<long>& element) {
    int n = element.size();
    for (int i = 0; i < n-1; ++i) {     
        for (int j = 0; j < n-i-1; ++j) {
            if (element[j] > element[j+1]) {
                int temp = element[j];
                element[j] = element[j+1];
                element[j+1] = temp;
            }
        }
    }
}

int main() {
    int totalNum, elementNum;
    cin >> totalNum;
    vector<long> element;
    for(int i = 0; i < totalNum; ++i) {
        cin >> elementNum;
        for(int k = 0; k < elementNum; ++k) {
            int input;
            cin >> input;
            element.push_back(input);
        }
    }

    bubbleSort(element);

    for(int num : element) {
        cout << num << " ";
    }

    return 0;
}
