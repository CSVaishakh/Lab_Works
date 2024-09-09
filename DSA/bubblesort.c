#include<stdio.h>
void main(){
    int n,i,j,temp,time=0,space=0;
    space+=6*4;
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
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                time+=4;
            }
            time++;
        }
        time++;
    }
    printf("The sorted list is:");
    time++;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
        time+=2;
    }
    printf("\nSpace Complexity: %d\n", space);
    time+=2;
    printf("Time Complexity: %d\n", time);
}