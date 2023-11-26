#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initDeque(struct Deque *dq) {
    dq->front = dq->rear = -1;
}

int isFull(struct Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE-1) || (dq->front == dq->rear+1);
}

int isEmpty(struct Deque *dq) {
    return dq->front == -1;
}

void insertFront(struct Deque *dq, int value) {
    if(isFull(dq)) {
        printf("\nDeque is Full!");
    } else {
        if(dq->front == -1) {
            dq->front = 0;
            dq->rear = 0;
        } else if(dq->front == 0) {
            dq->front = MAX_SIZE - 1;
        } else {
            dq->front = dq->front - 1;
        }
        dq->items[dq->front] = value;
        printf("Inserted element %d at the front\n", value);
    }
}


void display(struct Deque *dq) {
    if(isEmpty(dq)) printf("\nDeque is Empty!");
    else {
        int i = dq->front;
        printf("Deque elements: ");
        while(1) {
            printf("%d ", dq->items[i]);
            if(i == dq->rear) break;
            if(i == MAX_SIZE - 1) i=0;
            else i++;
        }
        printf("\n");
    }
    
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    int choice, value;

    do {
        printf("\n\nDeque Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Peek Front\n");
        printf("6. Display Deque\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                peekFront(&dq);
                break;
            case 6:
                display(&dq);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}