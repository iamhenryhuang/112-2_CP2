#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* element, int n) {
    for (int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) {
            if (element[j] > element[j+1]) {
                int temp = element[j];
                element[j] = element[j+1];
                element[j+1] = temp;
            }
        }
    }
}

int main() {
    int totalNum, elementNum, input;
    scanf("%d", &totalNum);

    int *element = (int*)malloc(totalNum * sizeof(int));
    int count = 0;

    for(int i = 0; i < totalNum; i++) {
        scanf("%d", &elementNum);
        for(int k = 0; k < elementNum; k++) {
            scanf("%d", &input);
            element[count++] = input;
        }
    }

    bubbleSort(element, count);

    for(int i = 0; i < count; i++) {
        printf("%d ", element[i]);
    }

    free(element);
    return 0;
}
