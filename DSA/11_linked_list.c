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
    new_node = (struct node *)malloc(sizeof(struct node));//allocatong memory in the heap
    new_node->data = item;//assigining the item to the data filed of the new node
    new_node->link = NULL;//setting the link field to null
    return new_node;
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
        printf("List is empty");
        return;
    }
    struct node *ptr = head;
    head = ptr->link;//updating the head to point to the secod node to delete the first node
    free(ptr);//free the space in the heap
    printf("Node deleted from the front\nStatus : ");
}
// function to delete a node from the end of the linked list
void del_Rear(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node* ptr = head;
    if (head->link == NULL){//checking if the list has only a single node
        head = NULL;//updating the head
        free(ptr);//free the heap
        printf("Node Deleted\nStatus : ");
        return;
    }
    struct node* temp = head;
    while(temp->link != NULL){//traversing to the second last node
        ptr = temp;
        temp = temp->link;//t
    }
    ptr->link = NULL;
    free(temp);
    printf("Node deleted from the rear\nStatus : ");
}
// function to delete a node at a certain postion
void delAny_Pos(){
    int key;
    printf("enter the key ");
    scanf("%d",&key);
    struct node *ptr = head;
    struct node* temp = NULL;
    while(ptr != NULL){
        if (ptr->data == key){
            temp->link = ptr->link;
            free(ptr);
            return;
        }
        temp = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL){
        printf("Search failed, Node not foud\n");
        return;
    }
    printf("Node deleted\nStatus : ");
}
// function to dipaly the linked list entirely 
void display(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
// insret function for menu
void insert(){
    int ch;
    while(true){
        printf("  INSERTION  ");
        printf("\n1.At Begining\n2.At End\n3.After a certain Node\n4.Return to main menu\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch){
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
        if(ch==4){
        	break;
        }else if(ch>4){
        	printf("Invalid choice\n");
        }
    }
}
// delete function for menu
void delete(){
    int ch;
    while(true){
        printf("  DELETION  ");
        printf("\n1.At Begining\n2.At End\n3.A certain Node\n4.Return to main menu\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch){
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
        if(ch==4){
        	break;
        }else if(ch>4){
        	printf("Invalid choice\n");
        }
    }
}
// main function
void main(){
    int ch;
    while(true){
        printf("\n  Linked List  \n");
        printf("1.Insert\n2.Delete\n3.Display\n4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
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