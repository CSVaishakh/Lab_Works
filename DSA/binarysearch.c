//a program to implemet binary search and also print its time and space complexity
#include <stdio.h>
//main function
void main() {
    int n, i, key, left, right, mid, time=0, space=0;
    space += 8*4;//incrementing the space by "no of variables" * size of an integer in bytes;'
    printf("Enter the no. of elements in the list: ");
    scanf("%d", &n);
    time+=2;
    int arr[n];
    space += n*4;
    printf("Enter the elements of the sorted list:\n");
    time++;
    for (i = 0; i < n; i++){
        printf("Element %d : ",i+1);
        scanf("%d", &arr[i]);
        time+=2;
    }
    printf("Enter the search key: ");
    scanf("%d", &key);
    time+=2;
    left = 0;
    right = n - 1;
    time+=2;
    while (left <= right) {
        mid = (left + right) / 2;
        time++;
        if(key == arr[mid]){
            printf("Element foud at position %d",mid+1);
            time+=2;
            break;
        }else if(key > arr[mid]){
            left = mid + 1;
            time+=2;
        }else if(key < arr[mid]){
            right = mid - 1;
            time+=2;
        }
    }
    if(left>right){
        printf("Element not found");
    }
    printf("\nSpace Complexity: %d\n", space);
    time+=2;
    printf("Time Complexity: %d\n", time);
}