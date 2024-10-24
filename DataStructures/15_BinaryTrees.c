#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Structure for a node in the binary tree
struct node {
    int data;
    struct node *left;  // Pointer to the left child
    struct node *right; // Pointer to the right child
};
// Global pointer to the root of the tree
struct node* root = NULL;
// Function to read an integer from the user
int read_item() {
    int item;
    printf("Enter the value: ");
    scanf("%d", &item);
    return item;
}
// Function to create a new node for the binary tree
struct node* create_node(int item) {
    struct node* new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
// Function to insert a node into the binary tree 
void insert() {
    struct node* new_node = create_node(read_item());
    if (root == NULL) {
        root = new_node;
        printf("Node %d inserted as root\n", new_node->data);
        return;
    }
    struct node* queue[100];
    int front = 0, rear = 0;  
    // Enqueue the root node
    queue[rear++] = root;
    // Level-order traversal to find the first available position
    while (front < rear) {
        struct node* current = queue[front++];  // Dequeue the front element
        // Check if the left child is available
        if (current->left == NULL) {
            current->left = new_node;
            printf("Node %d inserted on the left of %d\n", new_node->data, current->data);
            break;
        } else {
            queue[rear++] = current->left;  // Enqueue the left child
        }
        // Check if the right child is available
        if (current->right == NULL) {
            current->right = new_node;
            printf("Node %d inserted on the right of %d\n", new_node->data, current->data);
            break;
        } else {
            queue[rear++] = current->right;  // Enqueue the right child
        }
    }
}
// Function to perform in-order traversal of the binary tree
void inorder(struct node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
// Function to perform pre-order traversal of the binary tree
void preorder(struct node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}
// Function to perform post-order traversal of the binary tree
void postorder(struct node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}
// Main function
int main() {
    int choice = 0;
    while(true) {
        printf("\n1: Insert\n2: In-order Traversal\n3: Pre-order Traversal\n4: Post-order Traversal\n5: Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting the program\n");
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}