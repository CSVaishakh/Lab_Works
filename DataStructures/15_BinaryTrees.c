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

// Function to insert a node into the binary search tree
void insert(int item) {
    struct node* new_node = create_node(item);
    if (root == NULL) {
        root = new_node;
        printf("Node %d inserted as root\n", item);
        return;
    }
    
    struct node* current = root;
    struct node* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (item < current->data) {
            current = current->left;
        } else if (item > current->data) {
            current = current->right;
        } else {
            printf("Node with value %d already exists. Duplicates are not allowed.\n", item);
            free(new_node);
            return;
        }
    }
    
    if (item < parent->data) {
        parent->left = new_node;
        printf("Node %d inserted on the left of %d\n", item, parent->data);
    } else {
        parent->right = new_node;
        printf("Node %d inserted on the right of %d\n", item, parent->data);
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

// Function to display the tree structure
void display_tree(struct node* node, int level) {
    if (node == NULL) return;

    display_tree(node->right, level + 1);

    for (int i = 0; i < level; i++) printf(" ");
    printf("%d\n", node->data);

    display_tree(node->left, level + 1);
}

// Main function
int main() {
    int choice = 0;
    while(true) {
        printf("\n1: Insert\n2: In-order Traversal\n3: Pre-order Traversal\n");
        printf("4: Post-order Traversal\n5: Display Tree Structure\n6: Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert(read_item());
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
                printf("Tree structure:\n");
                display_tree(root, 0);
                break;
            case 6:
                printf("Exiting the program\n");
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}