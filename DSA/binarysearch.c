// A program to implement binary search and also print its time and space complexity
#include <stdio.h>

// Main function
void main() {
    // Declare variables
    int n, i, key, left=0, right=0, mid=0, time=0, space=0;
    
    // Calculate initial space complexity
    space += 8*4; // Incrementing the space by "no of variables" * size of an integer in bytes
    
    // Get the number of elements from the user
    printf("Enter the no. of elements in the list: ");
    scanf("%d", &n); // Reading the size of the array to be searched in
    time += 2; // Increment time for printf and scanf operations
    
    // Declare the array and update space complexity
    int arr[n];
    space += n*4; // Add space for the array (n elements * 4 bytes per int)
    
    // Input sorted elements
    printf("Enter the sorted elements:\n");
    time++;
    for (i = 0; i < n; i++) {
        printf("Element %d : ", i+1);
        scanf("%d", &arr[i]);
        time += 2; // Increment time for each iteration (printf and scanf)
    }
    
    // Get the search key from the user
    printf("Enter the search key: ");
    scanf("%d", &key);
    time += 2;
    
    // Initialize binary search boundaries
    left = 0;
    right = n - 1;
    time += 2;
    
    // Binary search algorithm
    while (left <= right) {
        mid = (left + right) / 2; // Calculate middle index
        time++;
        
        if (key == arr[mid]) {
            printf("Element found at position %d", mid+1);
            time += 2;
            break;
        } else if (key > arr[mid]) {
            left = mid + 1; // Search in the right half
            time += 2;
        } else if (key < arr[mid]) {
            right = mid - 1; // Search in the left half
            time += 2;
        }
    }
    
    // Check if element was not found
    if (left > right) {
        printf("Element not found");
    }
    
    // Print space and time complexity
    printf("\nSpace Complexity: %d\n", space);
    time += 2;
    printf("Time Complexity: %d\n", time);
}