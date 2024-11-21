#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 1001

typedef struct stack {
    int top;
    char items[MAX_EXPRESSION_LENGTH];
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char c) {
    stack->items[++stack->top] = c;
}

char pop(Stack* stack) {
    return stack->items[stack->top--];
}

int verify(char* expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')') {
            if (isEmpty(&stack)) {
                return -1;
            }
            pop(&stack);
        }
    }

    if (isEmpty(&stack)) {
        return 1;
    }
    return -1;
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    int* result = (int*)malloc(10000 * sizeof(int));
    memset(result, 0, 10000 * sizeof(int)); // Inicializa o array com zeros
    int i = 0;

    while (fgets(expression, sizeof(expression), stdin) != NULL) {
        if (expression[0] == '\n') {
            break;
        }
        
        expression[strcspn(expression, "\n")] = '\0';
        result[i] = verify(expression);
        i++;
    }
    
    for (int j = 0; j < i; j++) {
        if (result[j] == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    free(result);
    return 0;
}