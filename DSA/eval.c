#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
#define MAX_SIZE 100
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;
void push(Stack *s, char item) {
    if (s->top >= MAX_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = item;
}
char pop(Stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
void infixToPostfix(const char *infix, char *postfix) {
    Stack stack = {.top = -1};
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (stack.top != -1 && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top != -1 && stack.data[stack.top] == '(') {
                pop(&stack);
            }
        } else if (strchr("+-*/^", ch)) {
            while (stack.top != -1 && precedence(stack.data[stack.top]) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }
    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}
int evaluate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return b - a;
        case '*': return a * b;
        case '/': return b/a;
        case '^': return pow(a,b);
        default: return 0;
    }
}
int evaluatePostfix(const char *postfix) {
    Stack stack = {.top = -1};
    int value;

    for (int i = 0; postfix[i]; i++) {
        if (isalnum(postfix[i])) {
            if (isalpha(postfix[i])) {
                printf("Enter value for %c: ", postfix[i]);
                scanf("%d", &value);
            } else {
                value = postfix[i] - '0';
            }
            push(&stack, value);
        } else {
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, evaluate(a, b, postfix[i]));
        }
    }
    return pop(&stack);
}
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter Infix expression: ");
    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    infix[strcspn(infix, "\n")] = 0; // Remove newline if present
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
