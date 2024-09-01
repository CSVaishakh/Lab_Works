#include <stdio.h>
int time=0;
int space=2*4;

int binarysearch(int n, int a[], int key){
    int left = 0, right = n - 1;
    space += 2*4;
    while (left <= right) {
        int mid = (left + right) / 2;
        space += 4;
        if (key > a[mid]) {
            left = mid + 1;
            time+=2;
        }
        else if (key < a[mid]) {
            right = mid - 1;
            time+=2;
        }
        else{
            return mid;
            time++;
        }
    }
    return -1;
}

void main() {
    int n, i, key;
    space += 3*4;
    printf("Enter the no. of elements in the list: ");
    scanf("%d", &n);
    time+=2;
    int a[n];
    space += n*4;
    printf("Enter the elements of the sorted list:\n");
    time++;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        time+=2;
    }
    printf("Enter the search key: ");
    scanf("%d", &key);
    time+=2;
    int result = binarysearch(n, a, key);
    time+=2;
    if (result != -1) {
        printf("The element %d is present in the list at the position %d\n", key, result+1);
        time+=2;
    }
    else {
        printf("The element is not present in the list\n");
        time+=2;
    }
    printf("Space Complexity: %d\n", space);
    time+=2;
    printf("Time Complexity: %d\n", time);
}