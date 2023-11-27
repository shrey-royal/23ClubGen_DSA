/*
3. Ticket reservation system: An online ticket reservation system uses a queue to manage ticket bookings. When a customer requests a ticket, the system adds the request to the queue, and the ticket is booked in the order it was received. This ensures that customers are served in the order they requested tickets.

Sample data:

Customer 1: requested a ticket at 10:00 AM, for a show at 7:00 PM
Customer 2: requested a ticket at 10:05 AM, for a show at 8:00 PM
Customer 3: requested a ticket at 10:10 AM, for a show at 9:00 PM
Customer 4: requested a ticket at 10:15 AM, for a show at 7:00 PM
Explanation: In this scenario, each customer's ticket request is added to the queue in the order it was received. The tickets are booked in the order they were received, ensuring that customers are served in the order they requested tickets.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUEUE_SIZE 100

struct TicketRequest {
    int customerID;
    char requestTime[20];
    char showTime[20];
};

struct Queue {
    struct TicketRequest requests[MAX_QUEUE_SIZE];
    int front, rear;
};

void initQueue(struct Queue *queue) {
    queue->front = queue->rear = -1;
}

int isFull(struct Queue *queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty(struct Queue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(struct Queue *queue, struct TicketRequest data) {
    if(isFull(queue)) {
        printf("\nQueue is full. Cannot add more requests. \n");
        return;
    } 
    if(queue->front == -1) {
        queue->front = 0;
    }    
    queue->rear++;
    queue->requests[queue->rear] = data;
}

void dequeue(struct Queue *queue) {
    if(isEmpty(queue)) {
        printf("\nQueue is empty. No requests to dequeue. \n");
        return;
    }
    queue->front++;
}

void displayQueue(struct Queue *queue) {
    if(isEmpty(queue)) {
        printf("\nQueue is empty. No requests to display. \n");
        return;
    }
    printf("\nQueue of Ticket requests: \n");
    for(int i=queue->front; i<=queue->rear; i++) {
        printf("Customer %d: requested a ticket at %s, for a show at %s\n", queue->requests[i].customerID, queue->requests[i].requestTime, queue->requests[i].showTime);
    }
}

int main() {
    struct Queue ticketQueue;
    initQueue(&ticketQueue);

    //sample data
    struct TicketRequest req1 = {1, "10:00 AM", "7:00 PM"};
    struct TicketRequest req2 = {2, "10:05 AM", "8:00 PM"};
    struct TicketRequest req3 = {3, "10:10 AM", "9:00 PM"};
    struct TicketRequest req4 = {4, "10:15 AM", "7:00 PM"};

    //Adding requests to the queue
    enqueue(&ticketQueue, req1);
    enqueue(&ticketQueue, req2);
    enqueue(&ticketQueue, req3);
    enqueue(&ticketQueue, req4);

    //Displaying the queue
    displayQueue(&ticketQueue);

    //Simulating ticket bookings (dequeueing)
    dequeue(&ticketQueue);
    dequeue(&ticketQueue);
    dequeue(&ticketQueue);
    dequeue(&ticketQueue);

    //Displaying the queue after bookings
    // displayQueue(&ticketQueue);

    return 0;
}