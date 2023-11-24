#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue *q, int value) {
    if(q->rear == MAX_SIZE-1) printf("\nQueue is full");
    else {
        if(q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

void dequeue(struct Queue *q) {
    if(q->front == -1) printf("\nQueue is empty");
    else {
        printf("\nDequeued element: %d", q->items[q->front]);
        if(q->front == q->rear) q->front = q->rear = -1;
        else q->front++;
    }
}

int peekFront(struct Queue *q) {
    if(q->front == -1) printf("\nQueue is empty");
    else return q->items[q->front];
}

int peekRear(struct Queue *q) {
    if(q->front == -1) printf("\nQueue is empty");
    else return q->items[q->rear];
}

void display(struct Queue *q) {
    if(q->rear == -1) printf("\nQueue is empty");
    else {
        printf("\nQueue elements are: ");
        for(int i=q->front; i<=q->rear; i++) printf("%d ", q->items[i]);
        printf("\n");
    }
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;

    int choice, value;

    do {
        system("cls");
        display(&q);
        printf("\n\nQueue Menu: \n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peekfront and Peekrear");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case 2:
            dequeue(&q);
            printf("\n");
            break;

        case 3:
            printf("\nPeekfront: %d", peekFront(&q));
            printf("\nPeekrear: %d", peekRear(&q));
            printf("\n");
            break;

        case 4:
            display(&q);
            break;

        case 5:
            printf("\nExiting...\n");
            break;
        
        default:
            break;
        }
        system("pause");
    } while (choice != 5);
    
}