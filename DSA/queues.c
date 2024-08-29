#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define size 100
int queue[size],front = -1,rear = -1;
// function to check if the queue is full
bool isFull(int Max_Size){
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
void enqueue(int Max_Size){
    int val;
    if(isFull(Max_Size)==true){
        printf("Queue is full");
    }else if(front==-1 && rear==-1){
        front = rear = 0;
        printf("Enter the value to be added to the queue");
        scanf("%d",&val);
        queue[rear] = val;
    }else{
        rear++;
        printf("Enter the value to be added to the queue");
        scanf("%d",&val);
        queue[rear]=val;
    }
}
// function to dequeue an element from the queue
void dequeue(){
    if(isEmpty()==true){
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
    if(isEmpty()==true){
        printf("Queue is empty");
    }else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}

// main function 
int main(){
	int ch,Max_Size;
		printf("Enter the size of the queue");
		scanf("%d",&Max_Size);
		while(true){
			printf("\n*****Queues*****\n");
			printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Is the queue full\n5.Is the queue empty\n6.Exit\n");
			printf("Enter your choice : ");
			scanf("%d",&ch);
			printf("\n"); 
			switch(ch){
				case 1:
					enqueue(Max_Size);
					break;
				case 2:
					dequeue();
					break;
				case 3:
					display();
					break;
				case 4:
					if(isFull(Max_Size)==true){
						printf("Queue is full");
					}
					else{
						printf("Queue is not full");
					}
					break;
				case 5:        	
					if(isEmpty()==true){
						printf("Queue is empty");
					}
					else{
						printf("Queue is not empty");
					}
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
