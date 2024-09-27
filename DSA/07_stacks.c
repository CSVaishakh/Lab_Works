#include<stdio.h>
#include<stdbool.h>
int top =-1;
int stk[100];


void isFull(int Max_Size){
    if (top == Max_Size-1){
        printf("Stack is full");
    }
    else{
    	printf("Stack is not full");
    }
}
//isEmpty function
void isEmpty(){
    if (top == -1){
        printf("Stack is empty");
    }
    else{
    	printf("Stack is not empty");
    }
}
//push function
void push(int Max_Size){
    if(top == Max_Size-1){
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
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        int item = stk[top];
        top--;
        printf("Element sucessfully removed from the stack is %d",item);
    }
}
//peek function
void peek(){
    printf("The element at the top of the stack is %d",stk[top]);
}
//main function
int main(){
    int ch,Max_Size;
    printf("Enter the size of the stack ");
    scanf("%d",&Max_Size);
    while(true){
        printf("\n   *****STACK OPERATIONS*****   \n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.IS THE STACK FULL\n5.IS THE STACK EMPTY\n6.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        printf("\n"); 
        switch(ch){
        	case 1:
                push(Max_Size);
                break;
        	case 2:
            	pop();
   				break;
        	case 3:
            	peek();
            	break;
        	case 4:
            	isFull(Max_Size);
				break;
			case 5:        	
        		isEmpty();
        		break;
        }
        if(ch==6){
            printf("Exiting\n");
        	break;
        }else if(ch>6){
        	printf("Invalid choice\n");
        }
    }
    return 0;
}
