#include<stdio.h>
#include<sys/stat.h>

int main(){
    char path1[256];
    struct stat nfile;
    printf("Enter the name of the file");
    scanf("%s",path1);
    if(stat(path1,&nfile) == -1){
        perror("Error getting file stats");
        return 1;
    }

    printf("UserID:%d\n",nfile.st_uid);
    printf("UserID:%ld\n",nfile.st_blksize);
    printf("UserID:%1ld\n",nfile.st_atime);
    printf("UserID:%1ld\n",nfile.st_mtime);
    printf("UserID:%o\n",nfile.st_mode);
    printf("UserID:%1ld bytes\n",nfile.st_size);
    return 0;
}