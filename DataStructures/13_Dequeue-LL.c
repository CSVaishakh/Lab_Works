#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// creating the basic struct for the linked DE-queue with data and link fields
struct node{
    int data;
    struct node *link;
};
// initializing the top of the linked DE-queue
struct node* top = NULL;
// function to read the element to be inserted;
int read_item(){
    int item;
    printf("enter the value ");
    scanf("%d",&item);
    return item;
}
// function to create a new node for insertion or creation of a linked DE-queue
struct node* create_node(int item){
    struct node* new_node;
    new_node = (struct node *)malloc(sizeof(struct node));//allocating memory in the heap
    new_node->data = item;//assigining the item to the data filed of the new node
    new_node->link = NULL;//setting the link field to null
    return new_node;
}
// function to dispaly the linked DE-queue entirely 
void display(){
    if(top == NULL){//checking if the DE-queue  is empty
        printf("queue is empty");
        return;
    }
    struct node* ptr = top;
    while(ptr != NULL){//looping thought the DE-queue
        printf("%d ",ptr->data);//printing the  initial node
        ptr = ptr->link;//moving to the next node
    }
}

void in_Front(){
    struct node* temp = create_node(read_item());//creating a new temporary node using the create_node function
    if(temp == NULL){
        printf("Memory allocation failed");
        return;
    }
    temp->link = head;//setting the link of the created node to as head 
    head = temp;//updating head to point to the new node inserted
    printf("Node inserted at the front\nStatus : ");
}
// function to insert a new node at the end of the linked DE-queue
void in_Rear(){
    struct node* ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;//traversing through the DE-queue to find the end of the DE-queue
    }
    struct node* temp = create_node(read_item());//creating a new node to be inserted at the end
    ptr->link = temp;//updating the link field of the penultimate node to point to the new node inserted at the end 
    printf("Node inserted at the end\nStatus : ");
}

void del_Front(){
    if(head == NULL){
        printf("queue is empty, \n");
        return;
    }
    struct node *ptr = head;
    head = ptr->link;//updating the head to point to the secod node to delete the first node
    free(ptr);//free the space in the heap
    printf("Node deleted from the front\nStatus : ");
    display();
}
// function to delete a node from the end of the linked DE-queue
void del_Rear(){
    if(head == NULL){
        printf("queue is empty");
        return;
    }
    struct node* ptr = head;
    if (head->link == NULL){//checking if the DE-queue has only a single node
        head = NULL;//updating the head
        free(ptr);//free the heap
        printf("Node Deleted from the rear\nStatus : ");
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