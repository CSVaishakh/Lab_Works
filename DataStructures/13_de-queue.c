
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 3            
int queue[Max_Size];
int front =-1, rear = -1;bool isFull(){
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
void enqueue_front(int item){
    if(isFull()){
        printf("Queue is full");
    }else if(isEmpty()){
        front = rear = 0;
        queue[front]=item;
    
    }else{
        front = (front+1)%Max_Size;
        queue[front] = item;
    }
}
void enqueue_rear(int item){
    if(isFull()){
        printf("Queue is full");
    }else if(isEmpty()){
        front = rear = 0;
        queue[rear]=item;
    
    }else{
        rear = (rear+1)%Max_Size;
        queue[rear] = item;
    }
}
void dequeue_front(){
    if (isEmpty()){
        printf("Queue is empty");
    }else if(front == rear){
        printf("The item removed from the queue is %d",queue[front]);
        front = rear = -1;
    }else{
        printf("The item removed from the queue is %d",queue[front]);
        front = (front+1)%Max_Size ;
    }
}
void dequeue_rear(){
    if (isEmpty()){
        printf("Queue is empty");
    }else if(front == rear){
        printf("The item removed from the queue is %d",queue[rear]);
        front = rear = -1;
    }else{
        printf("The item removed from the queue is %d",queue[rear]);
        rear = (rear+1)%Max_Size ;
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue: ");
        int i = front;
        while (true) {
            printf("%d ", queue[i]);
            if (i == rear) break; // Stop when we reach the rear element
            i = (i + 1) % Max_Size; // Move to the next index in circular manner
        }
        printf("\n");
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