#include<stdio.h>
#include<stdlib.h>

int linearSearch(int*, int, int);
int binarySearch(int*, int, int);
void printArray(int*, int);

void main() {
    int size, choice, *arr, key, index;
    printf("\nEnter the size for the array: ");
    scanf("%d", &size);

    arr = malloc(size * sizeof(int));
    printf("\nGenerating random elements for the array: ");
    for(int i=0; i<size; i++) {
        arr[i] = rand() % 100;      // generating random numbers between 0 to 99
    }
    system("cls");    //clrscr();

    while(1) {
        printf("\nThe elements of the array are: ");
        printArray(arr, size);

        printf("\nEnter the element to search: ");
        scanf("%d", &key);
        system("cls");    //clrscr();
        
        printf("1. Linear Search\n2. Binary Search\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // linearSearch(arr, size, key);
                // index = linearSearch(arr, size, key);
                if((index = linearSearch(arr, size, key)) != -1) {
                    printf("\n%d found at index %d\n", key, index);
                } else {
                    printf("\n%d not found\n", key);
                }
                break;

            case 2:
                // binarySearch(arr, size, key);
                break;

            case 3:
                free(arr);
                exit(0);
            
            default:
                printf("\nInvalid choice\n");
                break;
        }//end switch
    }//end while
}//end main

void printArray(int* arr, int size) {
    printf("\nint arr[%d] = { ", size);
    for(int i=0; i<size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b };\n");
}

int linearSearch(int* arr, int size, int key) {
    int count = 0;
    if(size == 0) { //Base Case
        return -1;
    } else {    //Average Case
        for (int i = 0; i < size; i++) {
            count++;
            if(key == arr[i]) {
                return i;   //if found
            }
        }
    }
    printf("\nTotal number of comparisons: %d\n", count);
    return -1;  //if not found
}

/*
Tasks:

1. Phone Book Search: Given a list of phone numbers and corresponding names, find the name associated with a given phone number.

Sample Input:
char name[3][20] = {"Vishwa", "Dhiraj Sir", "Ankit"}; (%[^\n]s)
long long int ph[3] = {1234567890, 9876543210, 4567891230}; (%lld)

---
Sample Output:

Name: Vishwa
Phone Number: 1234567890 (use data type long long int* ph;)

Name: Dhiraj Sir
Phone Number: 9876543210

Name: Ankit
Phone Number: 4567891230

---
1. Search by name
2. Search by phone number

Enter your choice: 1

Enter the name to search: Ankit

Name: Ankit
Phone Number: 4567891230

---
1. Search by name
2. Search by phone number

Enter your choice: 2

Enter the phone number to search: 9876543210

Name: Dhiraj Sir
Phone Number: 9876543210

---
1. Search by name
2. Search by phone number

Enter your choice: 1

Enter the name to search: Mohak

Name not found, Please try again.

*/