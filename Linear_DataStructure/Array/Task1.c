#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int originalArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // You can change this array as needed
    int n = sizeof(originalArray) / sizeof(originalArray[0]);

    int nonPrimeOddArray[n];
    int divisibleArray[n];

    int divisibleBy;
    printf("Enter a number to check divisibility: ");
    scanf("%d", &divisibleBy);

    int nonPrimeOddCount = 0;
    int divisibleCount = 0;

    for (int i = 0; i < n; i++) {
        if (originalArray[i] % divisibleBy == 0) {
            divisibleArray[divisibleCount] = originalArray[i];
            divisibleCount++;
        }

        if (originalArray[i] % 2 != 0 && !is_prime(originalArray[i])) {
            nonPrimeOddArray[nonPrimeOddCount] = originalArray[i];
            nonPrimeOddCount++;
        }
    }

    printf("Non-prime odd numbers: ");
    for (int i = 0; i < nonPrimeOddCount; i++) {
        printf("%d ", nonPrimeOddArray[i]);
    }
    printf("\n");

    printf("Numbers divisible by %d: ", divisibleBy);
    for (int i = 0; i < divisibleCount; i++) {
        printf("%d ", divisibleArray[i]);
    }
    printf("\n");

    return 0;
}