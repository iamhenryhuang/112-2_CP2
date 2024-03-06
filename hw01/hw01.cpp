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
