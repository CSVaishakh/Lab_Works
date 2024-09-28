#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define a basic structure for a linked list node with data and link fields
struct node {
    int data;              // Data field to store integer data
    struct node *link;     // Link field to point to the next node in the list
};

// Initialize the head of the linked list as NULL
struct node* head = NULL;

// Function to read the integer value to be inserted into the linked list
int read_item() {
    int item;
    printf("Enter the value: ");
    scanf("%d", &item);
    return item;   // Return the value read from the user
}

// Function to create a new node with a given value
struct node* create_node(int item) {
    // Dynamically allocate memory for a new node in the heap
    struct node* new_node = (struct node *)malloc(sizeof(struct node));
    
    // Assign the value to the data field of the new node
    new_node->data = item;

    // Initialize the link field to NULL (new node points to nothing initially)
    new_node->link = NULL;
    
    return new_node;   // Return the newly created node
}

// Function to insert a new node at the front of the linked list
void in_Front() {
    // Create a new node using the create_node() function
    struct node* temp = create_node(read_item());

    // Check for memory allocation failure
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the link of the new node to the current head of the list
    temp->link = head;

    // Update the head to point to the new node
    head = temp;
    
    printf("Node inserted at the beginning\nStatus: ");
}

// Function to insert a new node at the end of the linked list
void in_Rear() {
    // Check if the list is empty, if yes, handle it as inserting at the front
    if(head == NULL) {
        in_Front();
        return;
    }

    struct node* ptr = head;
    
    // Traverse to the last node of the list
    while(ptr->link != NULL) {
        ptr = ptr->link;
    }

    // Create a new node and insert it at the end
    struct node* temp = create_node(read_item());
    ptr->link = temp;
    
    printf("Node inserted at the end\nStatus: ");
}

// Function to insert a new node after a specific node (based on a key)
void inAny_pos() {
    int key;
    printf("Enter the key (data of the node after which insertion is required): ");
    scanf("%d", &key);

    struct node *ptr = head;
    
    // Traverse to find the node with the specified key
    while(ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }

    // If the key is not found in the list
    if(ptr == NULL) {
        printf("Search failed, Node not found\n");
        return;
    }

    // Create a new node and insert it after the node with the key
    struct node* temp = create_node(read_item());
    temp->link = ptr->link;
    ptr->link = temp;
    
    printf("Node inserted at the desired position\nStatus: ");
}

// Function to delete the node at the front of the linked list
void del_Front() {
    // Check if the list is empty
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Store the current head in a temporary pointer
    struct node *ptr = head;

    // Move the head pointer to the next node
    head = ptr->link;

    // Free the memory of the old head node
    free(ptr);
    
    printf("Node deleted from the front\nStatus: ");
}

// Function to delete the node at the end of the linked list
void del_Rear() {
    // Check if the list is empty
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* ptr = head;
    
    // Check if there is only one node in the list
    if(head->link == NULL) {
        head = NULL;
        free(ptr);  // Free the only node
        printf("Node deleted\nStatus: ");
        return;
    }

    // Traverse to the second last node
    struct node* temp = head;
    while(temp->link != NULL) {
        ptr = temp;
        temp = temp->link;
    }

    // Disconnect the last node and free its memory
    ptr->link = NULL;
    free(temp);
    
    printf("Node deleted from the rear\nStatus: ");
}

// Function to delete a node at a specific position (based on a key)
void delAny_Pos() {
    int key;
    printf("Enter the key (data of the node to delete): ");
    scanf("%d", &key);

    struct node *ptr = head;
    struct node* temp = NULL;

    // Traverse the list to find the node with the key
    while(ptr != NULL) {
        if(ptr->data == key) {
            // If key is found, adjust the link of the previous node and delete the current node
            temp->link = ptr->link;
            free(ptr);
            printf("Node deleted\nStatus: ");
            return;
        }
        // Keep track of the previous node
        temp = ptr;
        ptr = ptr->link;
    }

    // If key was not found in the list
    if(ptr == NULL) {
        printf("Search failed, Node not found\n");
    }
}

// Function to display all nodes in the linked list
void display() {
    // Check if the list is empty
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* ptr = head;
    
    // Traverse through the list and print each node's data
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }

    printf("NULL\n");  // End of the list
}

// Function to handle insertion operations (menu-driven)
void insert() {
    int ch;
    while(true) {
        printf("  INSERTION  ");
        printf("\n1. At Beginning\n2. At End\n3. After a Certain Node\n4. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                in_Front();
                display();
                break;
            case 2:
                in_Rear();
                display();
                break;
            case 3:
                inAny_pos();
                display();
                break;
        }

        if(ch == 4) {
            break;
        } else if(ch > 4) {
            printf("Invalid choice\n");
        }
    }
}

// Function to handle deletion operations (menu-driven)
void delete() {
    int ch;
    while(true) {
        printf("  DELETION  ");
        printf("\n1. At Beginning\n2. At End\n3. A Certain Node\n4. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                del_Front();
                display();
                break;
            case 2:
                del_Rear();
                display();
                break;
            case 3:
                delAny_Pos();
                display();
                break;
        }

        if(ch == 4) {
            break;
        } else if(ch > 4) {
            printf("Invalid choice\n");
        }
    }
}

// Main function to run the program and handle user input for menu options
void main() {
    int ch;
    while(true) {
        printf("\n  Linked List  \n");
        printf("1. Insert\n2. Delete\n3. Display\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
