#include<stdio.h>
#include<stdlib.h>

void printArray(int*, int);
void bubbleSort(int*, int);
void selectionSort(int*, int);
void insertionSort(int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int); //helper function for quick sort
void swap(int*, int*);  //helper function for swapping

void main() {
    int choice, size;
    printf("\nEnter the size for the array: ");
    scanf("%d", &size);

    int arr[size];

    for(int i=0; i<size; i++) {
        arr[i] = rand() % 100;
    }

    printArray(arr, size);

    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\n6. Heap Sort\n7. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubbleSort(arr, size);
            printArray(arr, size);
            break;

        case 2:
            selectionSort(arr, size);
            printArray(arr, size);
            break;

        case 3:
            insertionSort(arr, size);
            printArray(arr, size);
            break;

        case 4:
            quickSort(arr, 0, size-1);
            printArray(arr, size);
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            exit(0);

        default:
            printf("\nInvalid choice\n");
            break;
    }//end switch
}//end main


//Function to print the array
void printArray(int* arr, int size) {
    printf("\narr[%d] = { ", size);
    for(int i=0; i<size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b }\n");
}

//Helper function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    // int temp = *a + *b;
    // *a = temp - *a;
    // *b = temp - *b;

    // *a ^= *b;
    // *b ^= *a;
    // *a ^= *b;
}

//Function to sort the array using bubble sort
void bubbleSort(int* arr, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size-i-1; j++) { //size-i-1 because the last element is already sorted
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


void selectionSort(int* arr, int size) {
    for(int i=0; i<size-1; i++) {
        int min = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) {
            swap(&arr[i], &arr[min]);
        }
    }
}

void insertionSort(int* arr, int size) {
    //optimised solution
    for(int i=1; i<size; i++) {     //passes
        int ele = arr[i];   //mark the element as key
        int j = i-1;    //j is the index of the element before the key
        while(j>=0 && arr[j] > ele) {
            arr[j+1] = arr[j];  //shift the element to the right
            j--;    //decrement j
        }
        arr[j+1] = ele; //insert the key at the correct position
    }
}

int partition(int* arr, int low, int high) {
    //Here, we will take the last element as the pivot
    int pivot = arr[high];

    //i will point to the index of the smaller element
    int i = low-1;

    //j will point to the index of the element being checked
    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]); //swap the elements that are smaller than the pivot
        }
    }

    //swap the pivot with the element at i+1
    swap(&arr[i+1], &arr[high]);

    //return the index of the pivot
    return i;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int indexOfPivot = partition(arr, low, high);

        // Sort the left subarray
        quickSort(arr, low, indexOfPivot - 1);

        // Sort the right subarray
        quickSort(arr, indexOfPivot + 1, high);
    }
}



/*
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Quick Sort
5. Merge Sort
6. Heap Sort
*/