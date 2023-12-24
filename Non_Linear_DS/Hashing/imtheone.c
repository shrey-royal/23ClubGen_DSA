#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 100

bool has[MAX + 1][2];

bool search(int X) {
    if(X >= 0) {
        if(has[X][0] == 1) return true;
        else return false;
    }

    X = abs(X);
    if(has[X][1] == 1) return true;
    
    return false;
}

void insert(int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            has[a[i]][0] = 1; // For non-negative numbers
        } else {
            has[abs(a[i])][1] = 1; // For negative numbers
        }
    }
}

void main() {
    int array[] = { -1, 9, -5, -8, -5, 2 };

    int size = sizeof(array)/sizeof(array[0]);
    insert(array, size);
    int X = 9;

    if(search(X) == true) {
        printf("\nPresent");
    } else {
        printf("\nNot Present");
    }
}