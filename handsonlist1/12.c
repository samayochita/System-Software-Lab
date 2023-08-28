#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{

    int fd1;
    fd1=open("file2.txt", O_RDWR);
    int mode;
    mode=fcntl(fd1, F_GETFL, 0 );
    printf("File mode is %d\n", mode);
    close(fd1);
    
    fd1=open("file2.txt", O_RDONLY);
   
    mode=fcntl(fd1, F_GETFL, 0 );
    printf("File mode is %d\n", mode);
    close(fd1);
    fd1=open("file2.txt", O_WRONLY);
   
    mode=fcntl(fd1, F_GETFL, 0 );
    printf("File mode is %d\n", mode);
close(fd1);
 return 0;
}