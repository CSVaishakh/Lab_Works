#include<stdio.h>
#include<stdbool.h>
#define Max_Size 3
int top =-1;
int stk[Max_Size];


bool isFull(){
    if (top == Max_Size-1){
        return true;
    }
    return false;
}
//isEmpty function
bool isEmpty(){
    if (top == -1){
        return true;
    }
    return false;
}
//push function
void push(){
    if(isFull()){
   	printf("Stack Overflow");
    }
    else{
        int item;
    	printf("Enter the element ");
        scanf("%d",&item);
        top++;
        stk[top] = item;
        printf("Element successfuly added to stack");
    }
}
//pop function
void pop(){
    if(isEmpty()){
        printf("Stack Underflow");
    }
    else{
        int item = stk[top];  
        top--;
        printf("Element sucessfully removed from the stack is %d",item);
    }
}
//peek function
void display(){
    for(int i = top;i > -1;i--){
        printf(" %d ",stk[i]);
    }
}
//main function
void main(){
    int ch;
    while(true){
        printf("\n   *****STACK OPERATIONS*****   \n");
        printf("1.Insertion\n2.Deletion\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        printf("\n"); 
        switch(ch){
        	case 1:
                push();
                break;
        	case 2:
            	pop();
   				break;
        	case 3:
            	display();
            	break;
        }
        if(ch==4){
            printf("Exiting\n");
        	break;
        }else if(ch>4){
        	printf("Invalid choice\n");
        }
    }
}