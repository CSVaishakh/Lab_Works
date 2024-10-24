#include<stdio.h>
void main(){
    // Declare variables and initialize time and space counters
    int n,i,key,found=0, time=0, space=0;

    space +=6*4;// Space for n, i, key, found, time, & space (6 integers)
    
    printf("Enter the no of elements in the list ");// Get number of elements from user
    scanf("%d",&n);
    time+=2;// Count operations for printf and scanf
    
    // Declare array and update space complexity
    int arr[n];
    space+=n*4;// Space for array (n integers)
    
    // Input array elements
    printf("Enter the elements of the list\n");
    time++;
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    	time+=2;// Count operations for scanf and loop increment
    }

    // Get search key from user
    printf("Enter the search key ");
    scanf("%d",&key);
    time+=2;// Count operations for printf and scanf

    // Linear search algorithm
    for(i=0;i<n;i++){
        if(key == arr[i]){
            printf("Element is found at the position %d",(i+1));
            found = 1;
            time += 4; // Count operations for comparison, printf, assignment, and break
            break; // Exit loop once element is found
        }
        time++; // Count operation for each comparison
    }
   // Check if element was not found
    if(!found){
        printf("Element not found");
        time += 2; // Count operations for comparison and printf
    }
    time++; // Count operation for the if condition check

    // Print space and time complexity
    printf("\nSpace Complexity : %d\n", space);
    time += 2; // Count operations for printf
    printf("Time Complexity : %d\n", time); 
}