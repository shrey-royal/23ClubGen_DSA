#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if(root == NULL) return createNode(data);

    if(data < root->data) {
        root->left = insert(root->left, data);
    }else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    struct ListNode* head = NULL;
    struct Node* root = NULL;
    int choice, data, min, max;

    do{
        system("cls");
        // printTree(root, 0);
        printf("\n\nBinary Tree Operations Menu\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Height\n");
        printf("7. Level Order Traversal\n");
        printf("8. Delete\n");
        printf("9. Find Min and Max\n");
        printf("10. convertBSTtoLinkedList\n");
        printf("11. Serialize Tree\n");
        printf("12. Deserialize Tree\n");
        printf("13. Find LCA\n");
        printf("14. Prune Tree\n");
        printf("15. Display Tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            
            case 2:
                //
                break;

            case 3:
                //
                break;

            case 4:
                //
                break;

            case 5:
                //
                break;

            case 6:
                //
                break;

            case 7:
                //
                break;

            case 8:
                //
                break;

            case 9:
                //
                break;

            case 10:
                //
                break;

            case 11:
                //
                break;

            case 12:
                //
                break;

            case 13:
                //
                break;

            case 14:
                //
                break;

            case 15:
                //
                break;

            case 0:
                printf("Exiting the program...");
                system("pause");
                break;
        }//end of switch
    } while(choice != 0);
}