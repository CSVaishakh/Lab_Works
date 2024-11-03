#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max_Size 3  // Set max size to 3
int dq[Max_Size], front = -1, rear = -1; // Initialize deque array and pointers for front and rear
// Function to check if the deque is full
bool isFull() {
    return (front == (rear + 1) % Max_Size); // Deque is full when front is just before rear (circular condition)
}
// Function to check if the deque is empty
bool isEmpty() {
    return (front == -1); // Deque is empty when front is -1
}
// Function to insert an element at the front of the deque
void enqueue_front(int x) {
    if (isFull()) { // Check if the deque is full
        printf("Deque is full, cannot insert %d\n", x);
        return;
    }else if (isEmpty()) { // If deque is empty, initialize front and rear to 0
        front = rear = 0;
    } else {
        front = (front - 1 + Max_Size) % Max_Size; // Move front backward circularly
    }
    dq[front] = x; // Insert the element at the front
}
// Function to insert an element at the rear of the deque
void enqueue_rear(int x) {
    if (isFull()) { // Check if the deque is full
        printf("Deque is full, cannot insert %d\n", x);
        return;
    } else if (isEmpty()) { // If deque is empty, initialize front and rear to 0
        front = rear = 0;
    } else {
        rear = (rear + 1) % Max_Size; // Move rear forward circularly
    }
    dq[rear] = x; // Insert the element at the rear
}
// Function to remove an element from the front of the deque
void dequeue_front() {
    if (isEmpty()) { // Check if the deque is empty
        printf("Deque is empty\n");
        return;
    }
    printf("%d successfully removed from front\n", dq[front]); // Print the element to be removed
    if (front == rear) { // If deque has only one element, reset front and rear to -1 (empty deque)
        front = rear = -1;
    } else {
        front = (front + 1) % Max_Size; // Move front forward circularly
    }
}
// Function to remove an element from the rear of the deque
void dequeue_rear() {
    if (isEmpty()) { // Check if the deque is empty
        printf("Deque is empty\n");
        return;
    }
    printf("%d successfully removed from rear\n", dq[rear]); // Print the element to be removed
    if (front == rear) { // If deque has only one element, reset front and rear to -1 (empty deque)
        front = rear = -1;
    } else {
        rear = (rear - 1 + Max_Size) % Max_Size; // Move rear backward circularly
    }
}
// Function to display all elements in the deque
void display() {
    if (isEmpty()) { // Check if the deque is empty
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements:\n");
    int i = front;
    // Loop to print deque elements from front to rear, adjusting for circular behavior
    while (true) {
        printf("%d\t", dq[i]); // Print the current element
        if (i == rear) break; // Stop when rear is reached
        i = (i + 1) % Max_Size; // Move forward circularly
    }
    printf("\n");
}
int main() { // Use the defined max Max_Size of the deque
    int x, choice;
    // Menu-driven loop to perform deque operations
    do {
        printf("DEQueues\n1. Insertion at FRONT\n2. Deletion from FRONT\n3. Insertion at REAR\n4. Deletion from REAR\n5. Display elements\n6. Exit\nEnter your choice:");
        scanf("%d", &choice); // Take user's choice

        // Switch case to handle each operation based on user input
        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &x); // Take the element to be inserted
                enqueue_front(x); // Insert at the front
                break;
            case 2:
                dequeue_front(); // Delete from the front
                break;
            case 3:
                printf("Enter element to be inserted: ");
                scanf("%d", &x); // Take the element to be inserted
                enqueue_rear(x); // Insert at the rear
                break;
            case 4:
                dequeue_rear(); // Delete from the rear
                break;
            case 5:
                display(); // Display the current state of the deque
                break;
            case 6:
                printf("\nExiting...\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice, please try again.\n"); // Handle invalid input
        }
    } while (true); // Continue until the user chooses to exit
    return 0; // Program ends
}