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
    if(isFull(dq)) printf("\nDeque is Full.");
    else {
        if(dq->front == -1) dq->front = dq->rear = 0;
        else if(dq->front == 0) dq->front = MAX_SIZE-1;
        else dq->front--;
        dq->items[dq->front] = value;
        printf("\nInserted %d at front.", value);
    }
}