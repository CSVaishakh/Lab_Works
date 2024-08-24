#include<stdio.h>
int main(){
    int n,i,j,temp;
    printf("Enter the no.of elements in the list to be sorted");
    scanf("%d",&n);
    int a[100];
    printf("Enter the elements of the list\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("The sorted list is:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}