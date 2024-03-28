// time complexity : O (n)
#include <stdio.h>

int main() {
    int days;
    scanf("%d", &days);
    int stockPrice[days];

    for(int i = 0; i < days; i++) {
        scanf("%d", &stockPrice[i]);
    }

    int minPrice = stockPrice[0];
    int maxProfit = 0;

    for (int i = 1; i < days; i++) {
        int currentProfit = stockPrice[i] - minPrice;
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
        if (stockPrice[i] < minPrice) {
            minPrice = stockPrice[i];
        }
    }

    printf("%d", maxProfit);

    return 0;
}

// time complexity : O*O (n*n)
#include <stdio.h>

int main() {
    int days;
    scanf("%d", &days);
    int stockPrice[days], maxProfit = 0;

    for(int i = 0; i < days; i++) {
        scanf("%d", &stockPrice[i]);
    }
    
    for(int slow = 0; slow < days - 1; slow++) {
        for(int fast = slow + 1; fast < days; fast++) {
            if(stockPrice[slow] < stockPrice[fast]) {
                int tempProfit = stockPrice[fast] - stockPrice[slow];
                if(tempProfit > maxProfit) {
                    maxProfit = tempProfit;
                }
            }
        }
    }

    printf("%d", maxProfit);
    
    return 0;
}
