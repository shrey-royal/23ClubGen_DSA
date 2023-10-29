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
    if(pos < 1) {
        printf("Invalid Position\n");
        
    } else {
        while(pos--) {
            if(pos == 0) {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = NULL;
                struct Node *temp = newNode;
                temp->next = *head;
                *head = temp;
            } else {
                head = &((*head)->next);
            }
        }
    }
}

//Search by value
int searchByValue(struct Node *head, int key) {
    while(head != NULL) {
        if(head->data == key) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int getLength(struct Node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

//Reversing the list
void reverseList(struct Node **head) {
    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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

//Delete from Beginning
void deleteAtBeginning(struct Node **head) {
    if(*head == NULL) {
        printf("\nList is Empty!\n");
        system("pause");
        return;
    } else {
        struct Node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

int main() {
    int choice, data, position, key;
    struct Node* head = NULL;
    
    while (1) {
        // system("pause");
        system("cls");
        printList(head);

        printf("\n\n\n1. Insert at beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Search By Value");
        printf("\n5. Length of the list");
        printf("\n6. Reverse the List");
        printf("\n7. Delete at beginning");
        printf("\n8. Delete at end");
        printf("\n9. Delete at Position");
        printf("\n10. Print list from beginning");
        printf("\n11. Print list from end");
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
        
        case 3:
            printf("\nEnter the position: ");
            scanf("%d", &position);
            printf("\nEnter the data: ");
            scanf("%d", &data);
            InsertAtPos(&head, data, position);
            break;

        case 4:
            printf("\nEnter the key to search from the list: ");
            scanf("%d", &key);
            // if(searchByValue(&head, key)) {
            //     printf("%d present in the list...", key);
            // } else {
            //     printf("%d is not present in the list...", key);
            // }
            searchByValue(head, key) ? printf("\n%d present in the list...", key) : printf("\n%d is not present in the list...", key);
            system("pause");
            break;

        case 5:
            printf("\nLength of the list: %d\n", getLength(head));
            system("pause");
            break;

        case 6:
            reverseList(&head);
            break;

        case 7:
            deleteAtBeginning(&head);
            break;
        
        case 10:
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