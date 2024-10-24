#include<stdio.h>
void main(){
    int n,i,j,temp,min,space=0,time=0;
    space+=7*4;
    printf("Enter the no.of elements in the list to be sorted");
    scanf("%d",&n);
    time+=2;
    int a[n];
    space+=n*4;
    printf("Enter the elements of the list\n");
    time++;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        time+=2;
    }
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
                time+=2;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        time+=4;
    }
       
    printf("The sorted array is");
    time++;
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
        time+=2;
    }
    printf("\nSpace complexity is %d\n",space);
    time+=2;
    printf("\nTime complexity is %d\n",time);
}