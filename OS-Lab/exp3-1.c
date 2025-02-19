#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main() { 
 printf("Process ID of the current process: %d\n", getpid()); 
 int pid = fork(); // Create a child process 
 if (pid > 0) { // Parent process 
 printf("Parent process waiting for the child to finish.\n"); 
 wait(NULL); // Wait for the child process to complete 
 execlp("ls", "ls", NULL); // Execute "ls" command directly 
 perror("execlp failed"); // Print error if execlp fails 
 exit(1); // Exit parent process 
 } 
 else if (pid == 0) { // Child process 
 printf("Child process (ID: %d) starts and ends.\n", getpid()); 
 exit(0); // Exit child process 
 } 
 else { // Fork failed 
 perror("Fork failed"); 
 exit(1); 
 } 
 return 0; 
} 
