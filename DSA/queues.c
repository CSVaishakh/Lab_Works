#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 5
int queue[size],front = -1,rear = -1;
// function to check if the queue is full
void isFull(){
    if(rear == Max_Size-1){
        printf("Queue is full");
    }else{
		printf("Queue is not full");
	}
    
}
// function to check if the queue is empty
void isEmpty(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }else{
		printf("Queue is not empty")
	}
}
// function to add an element to the queue
void enqueue(int item){
    int val;
    if(rear == Max_Size-1){
        printf("Queue is full");
    }else if(front==-1 && rear==-1){
        front = rear = 0;
        queue[rear] = item;
    }else{
        rear++;
        queue[rear]=item;
    }
}
// function to dequeue an element from the queue
void dequeue(){
    if(rear == -1){
        printf("Queue is empty");
    }else{
        printf("Element removed from the queue is %d",queue[front]);
        if(front==rear){
            front = rear = -1;
        }else{
            front++;
        }
    }
}
// function to print the queue
void display(){
    if(rear == -1){
        printf("Queue is empty");
    }else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}
// main function 
void main(){
	int ch,item;
	while(true){
		printf("\n*****Queues*****\n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Is the queue full\n5.Is the queue empty\n6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		printf("\n"); 
		switch(ch){
			case 1:
				printf("Enter the item to be inserted");
				scanf("%d",&item);
				enqueue(item);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				isFull();
				break;
			case 5:        	
				isEmpty()
				break;
		}
		if(ch==6){
			printf("Exiting\n");
			break;
		}else if(ch>6){
			printf("Invalid choice\n");
		}
	}
}