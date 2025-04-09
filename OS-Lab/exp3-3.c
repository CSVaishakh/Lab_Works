#include<stdio.h>
#include<dirent.h>

int main(){
    char dirName[256];
    DIR *drip;
    struct dirent *entry;
    printf("Enter the directory name");
    scanf("%s",dirName);
    drip = opendir(dirName);
    if(drip == NULL){
        printf("Error opening directory\n");
        return 1;
    }
    while((entry=readdir(drip))!=NULL){
        printf("%s",entry->d_name);
    }
    closedir(drip);
    return 0;
}