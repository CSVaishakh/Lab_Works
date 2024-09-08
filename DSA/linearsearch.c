#include<stdio.h>
void main(){
    int n,i,key,found=0, time=0, space=0;
    space +=4*4;
    printf("Enter the no of elements in the list ");
    scanf("%d",&n);
    time+=2;
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
    for(i=0;i<n;i++){
        if(key == arr[i]){
            printf("Element is found at the position %d",(i+1));
            found = 1;
            time+=4;
            break;
        }
        time++;
    }
    if(!found){
        printf("Element not found");
        time+=2;
    }time++;
    printf("\nSpace Complexity : %d\n",space);
    time+=2;
    printf("Time Complexity : %d\n",time); 
}