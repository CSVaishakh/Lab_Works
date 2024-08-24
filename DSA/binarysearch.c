#include <stdio.h>
int binarysearch(int n, int a[], int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (key > a[mid]) {
            left = mid + 1;
        }
        else if (key < a[mid]) {
            right = mid - 1;
        }
        else{
            return mid;
        }
    }
    
    return -1;
}

int main() {
    int n, i, key;
    printf("Enter the no. of elements in the list: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the sorted list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the search key: ");
    scanf("%d", &key);
    
    int result = binarysearch(n, a, key);
    
    if (result != -1) {
        printf("The element %d is present in the list at the position %d\n", key, result+1);
    }
    else {
        printf("The element is not present in the list\n");
    }
    return 0;
}