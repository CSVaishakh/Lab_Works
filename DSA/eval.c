#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100
#define STACK_SIZE 30
int top = -1;
char stk[STACK_SIZE];
char iexprsn[SIZE], pexprsn[SIZE];
bool isFull() { return top == STACK_SIZE - 1; }
bool isEmpty() { return top == -1; }
void push(char item) {
    if (isFull()) { 
        printf("Stack overflow\n"); 
        exit(EXIT_FAILURE); 
    }
    stk[++top] = item;
}
char pop() {
    if (isEmpty()) { 
        printf("Stack underflow\n"); 
        exit(EXIT_FAILURE); 
    }
    return stk[top--];
}
bool isOperator(char ch) { return ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-'; }
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
void infixToPostfix(const char* infix, char* postfix) {
    int j = 0;
    push('('); 
    strcat(iexprsn, ")");
    for (int i = 0; iexprsn[i] != '\0'; i++) {
        char ch = iexprsn[i];
        if (isspace(ch)) continue;
        if (isalpha(ch) || isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && stk[top] != '(') postfix[j++] = pop();
            if (!isEmpty()) pop(); // pop the '('
        } else if (isOperator(ch)) {
            while (!isEmpty() && isOperator(stk[top]) && precedence(stk[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        } else {
            printf("Invalid character '%c'\n", ch);
            exit(EXIT_FAILURE);
        }
    }
    postfix[j] = '\0';
}
void evaluatePostfix(const char* postfix) {
    int stack[STACK_SIZE], stackTop = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            stack[++stackTop] = ch - '0';
        } else if (isalpha(ch)) {
            int value;
            printf("Enter value for variable '%c': ", ch);
            if (scanf("%d", &value) != 1) {
                printf("Invalid input\n");
                exit(EXIT_FAILURE);
            }
            stack[++stackTop] = value;
        } else if (isOperator(ch)) {
            if (stackTop < 1) {
                printf("Invalid postfix expression\n");
                exit(EXIT_FAILURE);
            }
            int num2 = stack[stackTop--];
            int num1 = stack[stackTop--];
            switch (ch) {
                case '+': stack[++stackTop] = num1 + num2; break;
                case '-': stack[++stackTop] = num1 - num2; break;
                case '*': stack[++stackTop] = num1 * num2; break;
                case '/': 
                    if (num2 == 0) {
                        printf("Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    stack[++stackTop] = num1 / num2; 
                    break;
                case '^': stack[++stackTop] = (int)pow(num1, num2); break;
                default:
                    printf("Unknown operator '%c'\n", ch);
                    exit(EXIT_FAILURE);
            }
        } else {
            printf("Invalid character '%c' in postfix expression\n", ch);
            exit(EXIT_FAILURE);
        }
    }
    if (stackTop != 0) {
        printf("Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }
    printf("Result: %d\n", stack[stackTop]);
}
int main() {
    printf("Enter infix expression: ");
    fgets(iexprsn, SIZE, stdin);
    iexprsn[strcspn(iexprsn, "\n")] = '\0';
    infixToPostfix(iexprsn, pexprsn);
    printf("Postfix Expression: %s\n", pexprsn);
    evaluatePostfix(pexprsn);
    return 0;
}