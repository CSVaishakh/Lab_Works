#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 5
int queue[Max_Size],front = -1,rear = -1;
// function to check if the queue is full
bool isFull(){
    if(rear == Max_Size-1){
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
// function to add an element to the queue
void enqueue(int item){
    int val;
    if(isFull()){
        printf("Queue is full");
    }else if(isEmpty()){
        front = rear = 0;
        queue[rear] = item;
    }else{
        rear++;
        queue[rear]=item;
    }
}
// function to dequeue an element from the queue
void dequeue(){
    if(isEmpty()){
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
    if(isEmpty()){
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
