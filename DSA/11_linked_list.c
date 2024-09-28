#include<stdio.h>
#include<stdlib.h>
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
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->link = NULL;
    return new_node;
}
// dinction to insert a new node in the front of a linked list
void in_Front(){
    struct node* temp = create_node(read_item());
    if(temp == NULL){
        printf("Memory allocation failed");
        return;
    }
    temp->link = head;
    head = temp;
    printf("Node inserted at the begining\nStatus : ");
}
// function to insert a new node at the end of the linked list
void in_Rear(){
    struct node* ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    struct node* temp = create_node(read_item());
    ptr->link = temp;
    printf("Node inseryted at the end\nStatus : ");
}
// function to insert a new node at any position in the linekd list
void inAny_pos(){
    int key;
    printf("enter the value  ");
    scanf("%d",&key);
    struct node *ptr = head;
    do{
        ptr = ptr->link;
    }while(ptr != NULL && ptr->data != key);
    if (ptr == NULL){
        printf("Search failed, Node not foud");
        return;
    }
    struct node* temp = create_node(read_item());
    temp->link = ptr->link;
    ptr->link = temp;
    printf("Node inserted at desired positon\nStatus : ");
}
// function to delete a node fromm the begining of a linked list
void del_front(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct node *ptr = head;
    head = ptr->link;
    free(ptr);
    printf("Node deleated\nStatus : ");
}
// function to dipaly the linked list entirely 
void display(){
    struct node *ptr = head;
    if(ptr == NULL){
        printf("List is empty");
        return;
    }while(ptr != NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main(){
    in_Front();
    in_Rear();
    display();
    del_front();
    display();
    return 0;
}