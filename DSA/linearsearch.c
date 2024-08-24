#include<stdio.h>
int linearsearch(int arr[] , int n , int key){
    int i;
    for(i=0;i<n;i++){
        if (key == arr[i]){
            return i;
            break;
        }
    }
    return 0;
}


int main(){
    int n,i,key;
    printf("Enter the no.of elements in the list");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the list\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched in the lsit");
    scanf("%d",&key);
    int result = linearsearch(a,n,key);
    if(result != 0){
        printf("The element %d is present in the list at position %d",key,result+1);
    }
    else{
        printf("The element %d is not present in the lsit",key);
    }
}
