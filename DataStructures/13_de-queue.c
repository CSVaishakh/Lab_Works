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
// function to add an element to the queue from the front
void enqueue_front(int item){
    if(isFull()){
        printf("Queue is full");
        return;
    }else if(isEmpty()){
        front = rear = 0;
        queue[front] = item;
        return;
    }
    rear++;
    queue[front]=item;
    printf("Element succesfully added to the queue");
}
// function to add an element to the queue from the rear
void enqueue_rear(int item){
    if(isFull()){
        printf("Queue is full");
        return;
    }else if(isEmpty()){
        front = rear = 0;
        queue[rear] = item;
        return;
    }
    rear++;
    queue[rear]=item;
    printf("Element succesfully added to the queue");
}
// function to dequeue an element from the queue
void dequeue_front(){
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
// function to dequeue an element from the queue from the rear
void dequeue_rear(){
    if(isEmpty()){
        printf("Queue is empty");
    }else{
        printf("Element removed from the queue is %d",queue[rear]);
        if(front==rear){
            front = rear = -1;
        }else{
            rear--;
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
		printf("1.Enqueue at front\n2.Enqueue at rear\n3.Dequeue at front\n4.Dequeue at rear\n5.Display\n6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the item to be enqueued : ");
				scanf("%d",&item);
				enqueue_front(item);
				break;
			case 2:
				printf("Enter the item to be enqueued : ");
				scanf("%d",&item);
				enqueue_rear(item);
				break;
			case 3:
				dequeue_front();
				break;
			case 4:
				dequeue_rear();
				break;
			case 5:
				display();
				break;
            case 6:
                printf("Exiting\n");
                return;
            default:
                printf("Invalid choice\n");
		}
	}
}