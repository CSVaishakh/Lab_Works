	#include<stdio.h>

int time;
int space;
space = 2*4;

int linear_search(int n,int arr[],int key){
    int i;
    space+=4;
    for(i=0;i<n;i++){
    	if (key==arr[i]){
    	   return i;
    	   time+=1;
    	}
    	time+=2;
    }
    return 0;
}
void main(){
    int n,i,key;
    space +=3*4;
    printf("Enter the no of elements in the list ");
    scanf("%d",&n);
    time=+3;
    int arr[n];
    space+=n*4;
    printf("Enter the elements of the list\n");
    time++;
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    	time+=2;
    }
    printf("Enter the search key ");
    scanf("%d",&key);
    time+=2;
    int result = linear_search(n,arr,key);
    space+=4;
    if (result!=0){
    	printf("The element is present in the list at the position %d\n",(result+1));
    	time+=2;
    }
    else{
    	printf("The element is not present in the list\n");
    	time+=2;
    }
    printf("Space Complexity : %d\n",space);
    time+=2;
    printf("Time Complexity : %d\n",time); 
}
