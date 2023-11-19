#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

/*
Algorithm for push:

begin
 if stack is full
    print stack overflow
 endif
else
 increment top
 stack[top] assign value
end else
end procedure
*/

void push(int value) {
    if(top == MAX_SIZE - 1) {
        printf("\nStack OverFlow!\n");
        return;
    }
    else {
        top++;
        stack[top] = value;
        printf("\n%d pushes into the stack\n", value);
    }
}

/*
Algorithm for pop:

begin
 if stack is empty
    print stack underflow
 endif
else
 print value of stack[top]
 decrement top
end else
end procedure
*/

void pop() {
    if(top == -1) {
        printf("\nStack UnderFlow!\n");
        return;
    }
    else {
        printf("\nPopped %d from stack\n", stack[top]);
        top--;
    }
}

/*
Algorithm for Top:

begin 
  return stack[top]
end procedure
*/

int peek() {
    if(top == -1) {
        printf("\nStack UnderFlow!\n");
        return 0;
    }
    else return stack[top];
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX_SIZE - 1);
}

int size() {
    return top + 1;
}

void display() {
    if(top == -1) {
        printf("\nStack is UnderFlow.\n");
        return;
    }
    else {
        printf("Stack Elements: ");
        for(int i=top; i>=0; i--) {
            printf("%d, ", stack[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice, value;

    do {
        system("cls");
        display();
        printf("\n\nStack operations: ");
        printf("\n1. Push()");
        printf("\n2. Pop()");
        printf("\n3. Peek()");
        printf("\n4. isEmpty?");
        printf("\n5. isFull?");
        printf("\n6. size()");
        printf("\n7. display()");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the value to push into the stack: ");
                scanf("%d", &value);
                push(value);
                system("pause");
                break;

            case 2:
                pop();
                system("pause");
                break;

            case 3:
                printf("\nPeek Element from the stack is %d.\n", peek());
                system("pause");
                break;
            
            case 4:
                printf("\n-> is Stack Empty? : %d\n", isEmpty());
                system("pause");
                break;

            case 5:
                printf("\n-> is Stack Full? : %d\n", isFull());
                system("pause");
                break;

            case 6:
                printf("\nSize of the Stack is %d.\n", size());
                system("pause");
                break;

            case 7:
                display();
                system("pause");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 8);

    return 0;
}


// push, pop, peek, isEmpty, isFull, size.

/*
1. Matching Parentheses: One classic use case for a stack is to check whether parentheses in a given string are balanced or not. This problem is solved using a stack where each opening bracket is pushed into the stack and each closing bracket is popped out of the stack. If the stack is empty at the end of the string, then the parentheses are balanced. If there are any remaining brackets in the stack, then the parentheses are not balanced.

Input: "((2 + 3) * 5)"
Output: Balanced

Input: "((2 + 3) * 5))"
Output: Not balanced

Input: "{[()()]}"
Output: Balanced

Input: "{[(])}"
Output: Not balanced

Input: "{[()[]]{}()}"
Output: Balanced

Input: "}"
Output: Not balanced

2. Browser History: Another example of using a stack is managing the history of a web browser. Each time a user visits a new page, the URL of the page is added to the top of the stack. When the user clicks the "back" button, the top URL is popped off the stack and displayed. Similarly, if the user clicks the "forward" button, the URLs can be pushed back onto the stack.

Input: Visit "google.com", "facebook.com", "twitter.com", "linkedin.com" in that order, then click "back" button twice and "forward" button once.

Output:

Visiting "google.com"
Visiting "facebook.com"
Visiting "twitter.com"
Visiting "linkedin.com"
Going back to "twitter.com"
Going back to "facebook.com"
Going forward to "twitter.com"
Input: Visit "yahoo.com", "youtube.com", "stackoverflow.com", "github.com" in that order, then click "back" button three times and "forward" button once.

Output:

Visiting "yahoo.com"
Visiting "youtube.com"
Visiting "stackoverflow.com"
Visiting "github.com"
Going back to "stackoverflow.com"
Going back to "youtube.com"
Going back to "yahoo.com"
Going forward to "youtube.com"

*/