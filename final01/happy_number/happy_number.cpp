// unorder_set
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int sumOfSquare(int num) {
    int sum = 0;
    while(num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }

    return sum;
}

bool isHappy(int num) {
    unordered_set<int> seen;
    while(num != 1 && seen.find(num) == seen.end()) {
        seen.insert(num);
        num = sumOfSquare(num);
    }

    return num == 1;
}

int main() {
    int k;
    cin >> k;
    vector<int> results(k);

    for(int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        results[i] = isHappy(n);
    }

    for(int i = 0; i < k; ++i) {
        if(results[i] == 1) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    return 0;
}


// Floyd's Cycle-Finding Algorithm (fast & slow)
#include <iostream>
using namespace std;

int sumOfSquare(int num) {
    int sum = 0;
    while(num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }

    return sum;
}

bool isHappyNum(int num) {
    int fast = num;
    int slow = num;

    do {
    fast = sumOfSquare(sumOfSquare(fast));
    slow = sumOfSquare(slow);
    } while(fast != slow);

    return slow == 1;
}

int main() {
    int k;
    cin >> k;

    for(int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        if(isHappyNum(n)) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    return 0;
}
