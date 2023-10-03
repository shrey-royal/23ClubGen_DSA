#include<stdio.h>
#include<stdlib.h>  // for malloc

void main() {
    // int arr[] = {1,2,3,4,5};
    int size;

    printf("\nEnter the size for the array: ");
    scanf("%d", &size);
    int *arr = malloc(size * sizeof(int));

    // printf("\nEnter the elements for the array: ");
    printf("\nGenerating random elements for the array: ");
    for(int i=0; i<size; i++) {
        // printf("\nEnter the element for index %d: ", i);
        // scanf("%d", &arr[i]);
        arr[i] = rand() % 100;      // generating random numbers between 0 to 99
    }

    printf("\nThe elements of the array are: ");
    for(int i=0; i<size; i++) {
        printf("%d, ", arr[i]);
    }
}

/*
Now make a new array and add all the non-prime odd numbers from the previous array to the new array, then print it. then take another array and add all the numbers which is divisible by a number given by the user.

*/