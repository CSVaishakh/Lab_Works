#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Stack structure for DFS
typedef struct {
    int *items;   // Array to store the stack elements
    int top;      // Top index of the stack
    int capacity; // Capacity of the stack
} Stack;
// Function to initialize the stack
void initStack(Stack* s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->items = (int *)malloc(sizeof(int) * capacity);
}
// Function to free the stack
void freeStack(Stack* s) {
    free(s->items);
}
// Function to check if the stack is empty
int isStackEmpty(Stack* s) {
    return s->top == -1;
}
// Function to push an item onto the stack
void push(Stack* s, int value) {
    if (s->top == s->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = value;
}
// Function to pop an item from the stack
int pop(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Indicate empty stack
    }
    return s->items[s->top--];
}
// Function to perform DFS on the graph
void dfs(int graph[MAX][MAX], int start, int visited[], int n) {
    Stack s;
    initStack(&s, MAX); // Initialize the stack
    visited[start] = 1; // Mark the starting vertex as visited
    push(&s, start); // Push the starting vertex onto the stack
    while (!isStackEmpty(&s)) { // Continue until the stack is empty
        int current = pop(&s); // Pop the top vertex
        printf("%d ", current); // Print the current vertex
        // Visit all the adjacent vertices
        for (int i = n - 1; i >= 0; i--) { // Reverse order for correct DFS order
            if (graph[current][i] == 1 && !visited[i]) { // Check for unvisited adjacent vertices
                visited[i] = 1; // Mark it as visited
                push(&s, i); // Push the adjacent vertex onto the stack
            }
        }
    }
    freeStack(&s); // Free the stack memory
}
int main() {
    int n; // Number of vertices
    int graph[MAX][MAX]; // Adjacency matrix to represent the graph
    int visited[MAX] = {0}; // Array to track visited vertices
    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 and 1 only):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            scanf("%d", &input);
            if (input != 0 && input != 1) {
                printf("Invalid input! Only 0 and 1 are allowed.\n");
                return 1;
            }
            graph[i][j] = input;
        }
    }
    int startVertex;
    // Input the starting vertex for DFS
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }
    // Perform DFS traversal starting from the specified vertex
    printf("DFS traversal starting from vertex %d:\n", startVertex);
    dfs(graph, startVertex, visited, n);
    return 0;
}