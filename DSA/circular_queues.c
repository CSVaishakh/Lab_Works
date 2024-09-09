#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 5
int queue[Max_Size];
int front =-1, rear = -1;
bool isFull(){
    if((rear+1)%Max_Size==front){
        return true;
    }
	return false;
}
// function to check if the queue is empty
bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

void enqueue(item){
    if(isEmpty()){
        front = rear = 0;
        queue[rear]=item;
    
    }else if(isFull()){
        printf("Queue is full, OVERFLOW");
    }else{
        rear = (rear+1)%Max_Size;
        queue[rear] = item;
    }
}

void dequeue(){
    if (isEmpty()){
        printf("Queue is empty, UNDERFLOW");
    }else if(front == rear){
        printf("The item removed from the queue is %d",queue[front]);
        front = rear = -1;
    }else{
        printf("The item removed from the queue is %d",queue[front]);
        front = (rear+1)%Max_Size ;
    }
}

void display(){
    if(rear == -1){
        printf("Queue is empty");
    }else {
        printf("Elements in the queue: ");
        for(int i=front; i!=(rear+1)%Max_Size;i=(i+1)%Max_Size){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int ch,item;
	while(true){
		printf("\n*****Queues*****\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		printf("\n"); 
		switch(ch){
			case 1:
				printf("Enter the item to be enqueued : ");
				scanf("%d",&item);
				enqueue(item);
				break;
			case 2:
				dequeue();
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
