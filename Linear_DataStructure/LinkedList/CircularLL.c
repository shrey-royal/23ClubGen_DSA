#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertAtFront(struct Node* head, int data) {
    //insertatfront - circular ll
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    return head;
}

void print(struct Node* head) {
    //print - circular ll
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("\nList: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

struct Node* deleteByValue(struct Node* head, int data) {
    //deletebyvalue - circular ll
    if (head == NULL) {
        printf("\nList is empty\n");
        return head;
    }

    struct Node *temp = head, *prev = NULL;
    while(temp->data != data) { //taking temp to the node to be deleted
        if(temp->next == head) {
            printf("\nElement not found\n");
            return head;
        }
        prev = temp;        //we are storing the previous node
        temp = temp->next;  //we are moving forward
    }

    if (temp == head) {
        head = head->next;
        free(temp);
        return head;
    }

    prev->next = temp->next;
    free(temp);
}

void main() {
    struct Node *head = NULL;
    int data, choice;

    while (1) {
        system("cls");
        print(head);
        printf("\n1. Insert at front\n2. Print\n3. Delete by value\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                break;

            case 2:
                print(head);
                system("pause");
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteByValue(head, data);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}



/*
3 operations: 
Insert at front
print
deletebyvalue

---------------------------
Circular Doubly LL
---------------------------
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular doubly linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
    struct Node* prev;  // Pointer to the previous node
};

struct Node* head = NULL; // Initialize a global pointer to the head of the list

// Function to insert a node at the front of the circular doubly linked list
void insertAtFront(int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (head == NULL) {
        // If the list is empty, make the new node the head and point it to itself in both directions
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        // If the list is not empty, insert the new node at the front
        newNode->next = head;
        newNode->prev = head->prev; // The previous pointer of the new node should point to the previous head node
        head->prev->next = newNode; // Update the next pointer of the previous head node
        head->prev = newNode;   // Update the previous pointer of the head node
        head = newNode; // Update the head to the new node
    }
}

// Function to delete a node from the circular doubly linked list
void deleteNode(int key) {
    if (head == NULL) {
        // If the list is empty, there's nothing to delete
        return;
    }

    struct Node* current = head;
    struct Node* toDelete = NULL;

    do {
        if (current->data == key) {
            // If the node with the specified key is found, mark it for deletion
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != head);

    if (toDelete == head) {
        // If the head node is marked for deletion, update the head
        head = head->next;
    }

    // Adjust the pointers to remove the node from the list
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    // Free the memory of the deleted node
    free(toDelete);
}

// Function to print the circular doubly linked list
void printList() {
    if (head == NULL) {
        // If the list is empty, print a message
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;

    do {
        // Print the data in the current node and move to the next node
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);

    // Print "Head" to indicate the end of the list
    printf("Head\n");
}

int main() {
    // Insert nodes at the front of the list
    insertAtFront(1);
    insertAtFront(2);
    insertAtFront(3);
    insertAtFront(4);

    printf("Original List: ");
    // Print the list
    printList();

    // Delete nodes with specific values
    deleteNode(2);
    deleteNode(4);

    printf("List after deletion: ");
    // Print the updated list
    printList();

    return 0;
}



*/