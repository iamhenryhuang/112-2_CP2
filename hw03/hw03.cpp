#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;

int main() {
    // string input(without knowing how many inputs)
    string line;
    getline(cin, line);
    vector<int> rawNums;
    stringstream tempStr(line);

    // string from input save to vector
    int tempNums;
    while (tempStr >> tempNums) {
        rawNums.push_back(tempNums);
    }

    // using set to save unique subarrays
    unordered_set<int> elements;
    int sum = 0, left = 0, maxScore = 0;

    for (int right = 0; right < rawNums.size(); right++) {
        while (elements.find(rawNums[right]) != elements.end()) {
            elements.erase(rawNums[left]);
            sum -= rawNums[left];
            left++;
        }

        elements.insert(rawNums[right]);
        sum += rawNums[right];

        maxScore = max(maxScore, sum);
    }

    cout << maxScore;

    return 0;
}
