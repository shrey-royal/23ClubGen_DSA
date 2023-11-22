#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int calPoints(char ** ops, int opsSize) {
    int *stack = (int *)malloc(sizeof(int) * opsSize);
    int top = -1, sum = 0;

    for(int i=0; i<opsSize; i++) {
        if(strcmp(ops[i], "+") == 0) {
            stack[top + 1] = stack[top] + stack[top-1];
            top++;
        } else if(strcmp(ops[i], "D") == 0) {
            stack[top + 1] = stack[top] * 2;
            top++;
        } else if(strcmp(ops[i], "C") == 0) {
            stack[top] = 0;
            top--;
        } else {
            stack[top + 1] = atoi(ops[i]);
            top++;
        }
    }

    for(int i=top; i>=0; i--) {
        sum += stack[i];
    }

    free(stack);
    return sum;
}

int main() {
    char *ops1[] = {"5","2","C","D","+"};
    int opsSize1 = 5;
    printf("Output for ops1: %d\n", calPoints(ops1, opsSize1));

    char *ops2[] = {"5","-2","4","C","D","9","+","+"};
    int opsSize2 = 8;
    printf("Output for ops2: %d\n", calPoints(ops2, opsSize2));

    char *ops3[] = {"1","C"};
    int opsSize3 = 2;
    printf("Output for ops3: %d\n", calPoints(ops3, opsSize3));

    return 0;
}