#include <stdio.h>
void main() {
    int n, i, key, left=0, right=0, mid=0, time=0, space=0;
    space += 8*4;
    printf("Enter the no. of elements in the list: ");
    scanf("%d", &n);
    time += 2;
    int arr[n];
    space += n*4;
    printf("Enter the sorted elements:\n");
    time++;
    for (i = 0; i < n; i++) {
        printf("Element %d : ", i+1);
        scanf("%d", &arr[i]);
        time += 2;
    }
    printf("Enter the search key: ");
    scanf("%d", &key);
    time += 2;
    left = 0;
    right = n - 1;
    time += 2;
    while (left <= right) {
        mid = (left + right) / 2;
        time++;
        if (key == arr[mid]) {
            printf("Element found at position %d", mid+1);
            time += 2;
            break;
        } else if (key > arr[mid]) {
            left = mid + 1; 
            time += 2;
        } else if (key < arr[mid]) {
            right = mid - 1;
            time += 2;
        }
    }
    if (left > right) {
        printf("Element not found");
    }
    printf("\nSpace Complexity: %d\n", space);
    time += 2;
    printf("Time Complexity: %d\n", time);
}