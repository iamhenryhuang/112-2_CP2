#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int totalNum, elementNum;
    cin >> totalNum;
    vector<int> element;
    for(int i = 0; i < totalNum; ++i) {
        cin >> elementNum;
        for(int k = 0; k < elementNum; ++k) {
            int input;
            cin >> input;
            element.push_back(input);
        }
    }

    sort(element.begin(), element.end());

    for(int i = 0; i < element.size(); ++i) {
        cout << element[i] << " ";
    }

    return 0;
}
