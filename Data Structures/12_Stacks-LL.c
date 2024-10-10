#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// creating the basic struct for the linked stack with data and link fields
struct node{
    int data;
    struct node *link;
};
// initializing the top of the linked stack
struct node* top = NULL;
// function to read the element to be inserted;
int read_item(){
    int item;
    printf("enter the value ");
    scanf("%d",&item);
    return item;
}
// function to create a new node for insertion or creation of a linked stack
struct node* create_node(int item){
    struct node* new_node;
    new_node = (struct node *)malloc(sizeof(struct node));//allocating memory in the heap
    new_node->data = item;//assigining the item to the data filed of the new node
    new_node->link = NULL;//setting the link field to null
    return new_node;
}
// function to dispaly the linked stack entirely 
void display(){
    if(top == NULL){//checking if the stack  is empty
        printf("stack is empty,UNDERFLOW");
        return;
    }
    struct node* ptr = top;
    while(ptr != NULL){//looping thought the stack
        printf("%d ",ptr->data);//printing the  initial node
        ptr = ptr->link;//moving to the next node
    }
}
void push(){
    struct node* temp = create_node(read_item());//creating a new temporary node using the create_node function
    if(temp == NULL){
        printf("Memory allocation failed");
        return;
    }
    temp->link = top;//setting the link of the created node to as top 
    top = temp;//updating top to point to the new node inserted
    printf("Element succesfully pushed to the stack ");
}
void pop(){
    if(top == NULL){
        printf("stack is empty, UNDERFLOW\n");
        return;
    }
    struct node *ptr = top;
    top = ptr->link;//updating the top to point to the secod node to delete the first node
    printf("Element poped from the front %d",ptr->data);
    free(ptr);//free the space in the heap
}
void main() {
    int s = 0;
    while(true) {
        // Main menu for insertion, deletion, and display operations
        printf("\n1: Insertion\n2: Deletion\n3: Display\n4: Exit\nChoice: ");
        scanf("%d", &s);
        switch (s) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program");
                return;
            default: 
                printf("Invalid choice");
        }
}