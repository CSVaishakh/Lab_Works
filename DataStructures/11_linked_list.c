#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// creating the basic struct for the linked list with data and link fields
struct node{
    int data;
    struct node *link;
};
// initializing the head of the linked list
struct node* head = NULL;
// function to read the element to be inserted;
int read_item(){
    int item;
    printf("enter the value ");
    scanf("%d",&item);
    return item;
}
// function to create a new node for insertion or creation of a linked list
struct node* create_node(int item){
    struct node* new_node;
    new_node = (struct node *)malloc(sizeof(struct node));//allocating memory in the heap
    new_node->data = item;//assigining the item to the data filed of the new node
    new_node->link = NULL;//setting the link field to null
    return new_node;
}
// function to dispaly the linked list entirely 
void display(){
    if(head == NULL){//checking if the list  is empty
        printf("List is empty,UNDERFLOW");
        return;
    }
    struct node* ptr = head;
    while(ptr != NULL){//looping thought the list
        printf("%d -> ",ptr->data);//printing the  initial node
        ptr = ptr->link;//moving to the next node
    }
    printf("NULL\n");
}
// function to insert a new node in the front of a linked list
void in_Front(){
    struct node* temp = create_node(read_item());//creating a new temporary node using the create_node function
    if(temp == NULL){
        printf("Memory allocation failed");
        return;
    }
    temp->link = head;//setting the link of the created node to as head 
    head = temp;//updating head to point to the new node inserted
    printf("Node inserted at the begining\nStatus : ");
}
// function to insert a new node at the end of the linked list
void in_Rear(){
    struct node* ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;//traversing through the list to find the end of the list
    }
    struct node* temp = create_node(read_item());//creating a new node to be inserted at the end
    ptr->link = temp;//updating the link field of the penultimate node to point to the new node inserted at the end 
    printf("Node inserted at the end\nStatus : ");
}
// function to insert a new node at any position in the linekd list
void inAny_pos(){
    int key;
    printf("enter the key ");
    scanf("%d",&key);//reading key(data filed of the respective node)
    struct node *ptr = head;
    while(ptr != NULL && ptr->data != key){
        ptr = ptr->link;//traversing thourgh the list to find the node wrt the key
    }
    if (ptr == NULL){//if not foud ptr will be null
        printf("Search failed, Node not foud\n");
        return;
    }
    struct node* temp = create_node(read_item());
    temp->link = ptr->link;//updating the link field of the new inserted node wrt the key to point to the next node
     ptr->link = temp;//updating the link field of the node to point to the new node 
    printf("Node inserted at desired positon\nStatus : ");
}
// function to delete a node fromm the begining of a linked list
void del_Front(){
    if(head == NULL){
        printf("List is empty, UNDERFLOW\n");
        return;
    }
    struct node *ptr = head;
    head = ptr->link;//updating the head to point to the secod node to delete the first node
    free(ptr);//free the space in the heap
    printf("Node deleted from the front\nStatus : ");
    display();
}
// function to delete a node from the end of the linked list
void del_Rear(){
    if(head == NULL){
        printf("List is empty, UNDERFLOW\n");
        return;
    }
    struct node* ptr = head;
    if (head->link == NULL){//checking if the list has only a single node
        head = NULL;//updating the head
        free(ptr);//free the heap
        printf("Node Deleted\nStatus : ");
        display();
        return;
    }
    struct node* temp = head;
    while(temp->link != NULL){//traversing to the second last node
        ptr = temp;
        temp = temp->link;//t
    }
    ptr->link = NULL;//updating the link field of the second last node to be null to delteing the last node 
    free(temp);
    printf("Node deleted from the rear\nStatus : ");
    display();
}
// function to delete a node at a certain postion
void delAny_Pos(){
    int key;
    printf("enter the key ");
    scanf("%d",&key);//reading the data field of the key to be deleted
    struct node *ptr = head;
    struct node* temp = NULL;
    while(ptr != NULL){
        if (ptr->data == key){//locating the node to be deleted wrt to the key
            temp->link = ptr->link;//updating the previous node to the point to the node after the node to be deleted
            free(ptr);//freeing the heap 
            display();
            return;
        }
        temp = ptr;
        ptr = ptr->link;//traversing though the node
    }
    if (ptr == NULL){
        printf("Search failed, Node not foud\n");
        return;
    }
    printf("Node deleted\nStatus : ");
    display();
}
void main() {
    int s = 0;
    while(true) {
        // Main menu for insertion, deletion, and display operations
        printf("\n1: Insertion\n2: Deletion\n3: Display\n4: Exit\nChoice: ");
        scanf("%d", &s);
        switch (s) {
            case 1:
                // Submenu for choosing where to insert
                printf("\nSelect Position\n1: Front\n2: End\n3: Between Nodes\nChoice: ");
                scanf("%d", &s);
                switch (s) {
                    case 1: 
                        in_Front();
                        display();
                        break;  // Insert at the front
                    case 2: 
                        in_Rear();
                        display();
                        break;    // Insert at the end
                    case 3: 
                        inAny_pos();
                        display();
                        break; // Insert at a specific position
                    default: printf("Wrong Input\n");
                }
                break;
            case 2:
                // Submenu for choosing which node to delete
                printf("\nSelect Position\n1: Front\n2: End\n3: Specific Node\nChoice: ");
                scanf("%d", &s);
                switch (s) {
                    case 1: 
                        del_Front();
                        break;  // Delete from the front
                    case 2: 
                        del_Rear();
                        break;    // Delete from the end
                    case 3: 
                        delAny_Pos();
                        break; // Delete a specific node    char option;
                    default: printf("Wrong Input\n");
                }
                break;
            case 3:
                display();  // Display the list
                break;
            case 4:
                printf("Exiting....");
                return;
            case 5:
                printf("inavalid choice");
        }   
    }
}