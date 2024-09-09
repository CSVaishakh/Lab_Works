#include<stdio.h>
#include<stdlib.h>
#define Max_Size 5
int queue[Max_Size];
int front = rear = -1;

void enqueue(item){
    if(rear==-1&&front==-1){
        fornt = rear = 0;
        queue[rear]=item;
    
    }else if((rear+1)%Max_Size==front){
        printf("Queue is full, OVERFLOW");
    }else{
        rear = (rear+1)%Max_Size;
        queue[rear] = item;
    }
}

void dequeue(){
    if (rear == -1){
        printf("Queue is empty, UNDERFLOW");
    }else if(front == rear){
        printf("The item removed from the queue is",queue[front]);
        front = rear = -1;
    }else{
        printf("The item removed from the queue is",queue[front]);
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
void isEmpty(){
    if(rear == -1){
        printf("Queue is Empty");
    }else{
        printf("Queue is not empty");
    }
}

void isFull(){
    if ((rear+1)%Max_Size == front){
        printf("Queue is Full");
    }else{
        printf("Queue is not full");
    }
}

int main(){
    int choice,item;
    while(1){
        printf("****Circular-Queues*****")
        printf("Enter your choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.isEmpty\n5.isFull\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the item to enqueue:\n");
                scanf("%d",&item);
                enqueue(item);
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isEmpty();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}