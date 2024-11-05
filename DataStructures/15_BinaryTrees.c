#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* root = NULL;
int read_item(){
    int item;
    printf("Enter the value ");
    scanf("%d",&item);
    return item;
}
struct node* create_node(int item) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
int getHeight(struct node* root) {
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
bool isComplete(struct node* root, int level, int height) {
    if (root == NULL) return (level >= height);
    return isComplete(root->left, level + 1, height) && 
           isComplete(root->right, level + 1, height);
}
bool insertAtLevel(struct node** node, int level, int value) {
    if (*node == NULL && level == 0) {
        *node = create_node(value);
        printf("Inserted %d as the root node\n", value);
        return true;
    }
    if (level == 0) return false;
    if (*node == NULL) return false;   
    if ((*node)->left == NULL && level == 1) {
        (*node)->left = create_node(value);
        printf("Inserted %d on the left of %d\n", value, (*node)->data);
        return true;
    }
    if (insertAtLevel(&((*node)->left), level - 1, value)) {
        return true;
    }
    if ((*node)->right == NULL && level == 1) {
        (*node)->right = create_node(value);
        printf("Inserted %d on the right of %d\n", value, (*node)->data);
        return true;
    }
    return insertAtLevel(&((*node)->right), level - 1, value);
}
void insertLevelOrder(int value) {
    if (root == NULL) {
        root = create_node(value);
        printf("Inserted %d as the root node\n", value);
        return;
    }
    int height = getHeight(root);
    bool inserted = false;
    if (!isComplete(root, 0, height)) {
        inserted = insertAtLevel(&root, height - 1, value);
    }
    if (!inserted) {
        inserted = insertAtLevel(&root, height, value);
    }
}
void inorder(struct node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
void preorder(struct node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}
void postorder(struct node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}
int main() {
    int choice;
    while(1) {
        printf("\n1: Insert\n2: In-order Traversal\n3: Pre-order Traversal\n4: Post-order Traversal\n5: Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insertLevelOrder(read_item());
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