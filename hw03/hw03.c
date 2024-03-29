#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[10000];
    fgets(line, sizeof(line), stdin);

    int* rawNums = malloc(sizeof(int) * 10000); // dynamically allocate array for integers
    int numCount = 0; // count of numbers in the array
    char* token = strtok(line, " \n");
    while (token != NULL) {
        rawNums[numCount++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    int elements[10000] = {0}; // array to store unique elements
    int sum = 0, left = 0, maxScore = 0;
    for (int right = 0; right < numCount; right++) {
        // Check if current number is already in 'elements' set
        while (elements[rawNums[right]] > 0) {
            elements[rawNums[left]]--;
            sum -= rawNums[left];
            left++;
        }

        elements[rawNums[right]]++;
        sum += rawNums[right];

        if (sum > maxScore) {
            maxScore = sum;
        }
    }

    printf("%d\n", maxScore);

    free(rawNums); // Don't forget to free dynamically allocated memory
    return 0;
}
