#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definition Section
#define MAX_SIZE 5

//Global Declaration Section
struct Queue {
    int data;
    struct Queue *front;
    struct Queue *rear;
};

struct Queue *front = NULL;
struct Queue *rear = NULL;

//function prototype
void enqueue(struct Queue, int data);
void dequeue();
int peekFront();
int peekRear();
void display();
bool isEmpty();
bool isFull();

int main() {
    int choice, data;
}

//function definition for enqueue
 enqueue(int data) {
    //check if queue is full
    if()
}