#include<stdio.h>
void main(){
    int n,i,j,temp,min,space=0,time=0;
    space+=7*4;
    printf("Enter the no.of elements in the lsit to be sorted");
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
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                min = j;
                time+=2;
            }
        }
        temp=a[j+1];
        a[j+1]=a[j];
        a[j]=temp;
        time+=4;
       
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