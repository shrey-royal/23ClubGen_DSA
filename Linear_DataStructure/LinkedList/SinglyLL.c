#include<stdio.h>
#include<stdlib.h>

//create a node
struct Node {
    int data;   //store the data/value
    struct Node* next;  //store the address of the next node
};

//Insert at beginning
void InsertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

//Insert at End
void InsertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *last = *head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

//Insert at given position
void InsertAtPos(struct Node** head, int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    //next lecture
}


//print list from beginning
void printList(struct Node* head) {
    printf("\nList ==>\t");
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}



int main() {
    int choice, data;
    struct Node* head = NULL;
    
    while (1) {
        // system("pause");
        system("cls");
        printList(head);

        printf("\n\n\n1. Insert at beginning");
        printf("\n2. Insert at End");
        printf("\n88. Print list from beginning");
        printf("\n99. Print list from end");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // system("cls");
            printf("\nEnter the data: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;

        case 2:
            // system("cls");
            printf("\nEnter the data: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;
        
        
        
        case 88:
            // system("cls");
            printf("\nList from beginning: ");
            printList(head);
            system("pause");
            break;

        case 0:
            printf("\nExiting...\n");
            // system("pause");
            exit(0);
            break;
        
        default:
            break;
        }



    }
    


}