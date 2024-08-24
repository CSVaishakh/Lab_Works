#include<stdio.h>
int main(){
    int n,i,j,temp,min;
    printf("Enter the no.of elements in the lsit to be sorted");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the list\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        min = i;
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                min = j;
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("The sorted array is");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
}