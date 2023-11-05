#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* initializeList() {
    return NULL;
}

// Insert at front
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Insert a node after a specific node
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    if(prevNode == NULL) {
        printf("Previous Node cannot be NULL. \n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = prevNode;
    newNode->next = prevNode->next;

    if(prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
    return head;
}

// Insert a node before a specific node
struct Node* insertBeforeNode(struct Node* head, struct Node* nextNode, int data) {
    if(nextNode == NULL) {
        printf("Next node cannot be null.\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;

    if(nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        //Update the head of the list
        head = newNode;
    }
    nextNode->prev = newNode;
    return head;
}

//Search for a node with a specific value in the list
struct Node* search(struct Node* head, int value) {
    while(head != NULL) {
        if(head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

//insert at index
struct Node* insertAtIndex(struct Node* head, int data, int index) {
    if(index < 0) {
        printf("Invalid index. Index must be non-negative.\n");
        return head;
    }

    if(index == 0 || head == NULL) {
        return insertAtFront(head, data);
    }

    struct Node* current = head;
    int currentIndex = 0;

    while(current != NULL && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if(current == NULL) {
        printf("Index out of bounds. Cannot insert at index %d.\n", index);
        return head;
    }

    return insertBeforeNode(head, current, data);
}

//deletefromfront
struct Node* deleteFromFront(struct Node* head) {
    if(head == NULL) {
        printf("The list is empty. Cannot delete from an empty list.\n");
        return NULL;
    }

    struct Node* newHead = head->next;
    free(head);

    if(newHead != NULL) {
        newHead->prev = NULL;
    }
    return newHead;
}

//deletefromend
struct Node* deleteFromEnd(struct Node* head) {
    if(head == NULL) {
        printf("The list is empty. Cannot delete from an empty list.\n");
        return NULL;
    }

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head;
}

//delete by value
struct Node* deleteNode(struct Node* head, struct Node* nodeToDelete) {
    if(nodeToDelete == NULL) {
        printf("Node to be deleted cannot be NULL.\n");
        return head;
    }

    if(nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    } else {
        //Node to delete is the head of the list
        head = nodeToDelete->next;
    }

    if(nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    free(nodeToDelete);
    return head;
}

//delete a node at specified index
struct Node* deleteAtIndex(struct Node* head, int index) {
    if(index < 0) {
        printf("Invalid index. Index must be non-negative.\n");
        return head;
    }

    if(head == NULL) {
        printf("The list is Empty. Cannot delete from an empty list.\n");
        return head;
    }

    if(index == 0) {
        return deleteFromFront(head);
    }

    struct Node* current = head;
    int currentIndex = 0;

    while(current != NULL && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if(current == NULL) {
        printf("Index out of bounds. Cannot delete at index %d.\n", index);
        return head;
    }

    return deleteNode(head, current);
}



// Traverse forward
void traverseForward(struct Node* head) {
    printf("\nJust List > \tNULL <-> ");
    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}

//traverse backwards
void traverseBackward(struct Node* head) {
    if(head == NULL) {
        printf("List (Backward): NULL\n");
        return;
    }
    //Find the last node in the list
    while(head->next != NULL) {
        head = head->next;
    }

    printf("\nJust List > \tNULL <-> ");
    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n\n");
}

//getLength
int getLength(struct Node* head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

//reverse the order of the list
struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;

    while(current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL) {
        head = temp->prev;
    }
    return head;
}

//destroyList
void destroyList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void main() {
    struct Node* list = initializeList();

    int choice, data, index;
    struct Node* node;
    do {
        system("cls");
        traverseForward(list);
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Node\n");
        printf("5. Insert at Index\n");
        printf("6. Delete from Front\n");
        printf("7. Delete from End\n");
        printf("8. Delete a Node\n");
        printf("9. Delete at Index\n");
        printf("10. Traverse Forward\n");
        printf("11. Traverse Backward\n");
        printf("12. Search for a Node\n");
        printf("13. Get Length\n");
        printf("14. Reverse List\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                list = insertAtFront(list, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                list = insertAtEnd(list, data);
                break;
            case 3:
                printf("Enter data to insert after: ");
                scanf("%d", &data);
                printf("Enter the value of the node after which to insert: ");
                scanf("%d", &index);
                node = search(list, index);
                list = insertAfterNode(list, node, data);
                break;
            case 4:
                printf("Enter data to insert before: ");
                scanf("%d", &data);
                printf("Enter the value of the node before which to insert: ");
                scanf("%d", &index);
                node = search(list, index);
                list = insertBeforeNode(list, node, data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the index at which to insert: ");
                scanf("%d", &index);
                list = insertAtIndex(list, data, index);
                break;
            case 6:
                list = deleteFromFront(list);
                break;
            case 7:
                list = deleteFromEnd(list);
                break;
            case 8:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                node = search(list, data);
                list = deleteNode(list, node);
                break;
            case 9:
                printf("Enter the index of the node to delete: ");
                scanf("%d", &index);
                list = deleteAtIndex(list, index);
                break;
            case 10:
                traverseForward(list);
                system("pause");
                break;
            case 11:
                traverseBackward(list);
                system("pause");
                break;
            case 12:
                printf("Enter the value to search for: ");
                scanf("%d", &data);
                node = search(list, data);
                if (node != NULL) {
                    printf("Node found in the list.\n");
                } else {
                    printf("Node not found in the list.\n");
                }
                system("pause");
                break;
            case 13:
                printf("Length of the list: %d\n", getLength(list));
                system("pause");
                break;
            case 14:
                list = reverseList(list);
                break;
            case 15:
                destroyList(list);
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 15);
}