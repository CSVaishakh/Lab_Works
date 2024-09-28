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
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->link = NULL;
    return new_node;
}
// function to insert a new node in the front of a linked list
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
    printf("Node inserted at the end\nStatus : ");
}
// function to insert a new node at any position in the linekd list
void inAny_pos(){
    int key;
    printf("enter the key ");
    scanf("%d",&key);
    struct node *ptr = head;
    while(ptr != NULL && ptr->data != key){
        ptr = ptr->link;
    }
    if (ptr == NULL){
        printf("Search failed, Node not foud\n");
        return;
    }
    struct node* temp = create_node(read_item());
    temp->link = ptr->link;
    ptr->link = temp;
    printf("Node inserted at desired positon\nStatus : ");
}
// function to delete a node fromm the begining of a linked list
void del_Front(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct node *ptr = head;
    head = ptr->link;
    free(ptr);
    printf("Node deleted from the front\nStatus : ");
}
// function to delete a node from the end of the linked list
void del_Rear(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node* ptr = head;
    if (head->link == NULL){
        head = NULL;
        free(ptr);
        printf("Node Deleted\nStatus : ");
        return;
    }
    struct node* temp = head;
    while(temp->link != NULL){
        ptr = temp;
        temp = temp->link;
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