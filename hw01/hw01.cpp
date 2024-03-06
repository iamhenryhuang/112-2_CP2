#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int days, maxProfit = 0;
    cin >> days;
    vector<int> stockPrice(days);

    for(int i = 0; i < days; i++) {
        cin >> stockPrice[i];
    }

    if (days < 2) {
        cout << "0";
        return 0;
    }

    int minPrice = stockPrice[0];

    for(int i = 1; i < days; i++) {
        int currentProfit = stockPrice[i] - minPrice;
        maxProfit = max(maxProfit, currentProfit);
        minPrice = min(minPrice, stockPrice[i]);
    }

    cout << maxProfit;

    return 0;
}

/*#include <iostream>
#include <vector>
using namespace std;

int main() {
    int days, maxProfit = 0;
    cin >> days;
    vector<int> stockPrice(days);
    vector<int> tempProfit;

    for(int i = 0; i < days; i++) {
        cin >> stockPrice[i];
    }

    for(int slow = 0; slow < days - 1; slow++) {
        for(int fast = slow + 1; fast < days; fast++) {
            if(stockPrice[slow] < stockPrice[fast]) {
                tempProfit.push_back(stockPrice[fast] - stockPrice[slow]);
            }
        }
    }

    int maxNum = 0;

    if (!tempProfit.empty()) {
        maxNum = tempProfit[0];

        for (int num : tempProfit) {
            if (num > maxNum) {
                maxNum = num;
            }
        }
    }

    cout << maxNum;

    return 0;
}*/
