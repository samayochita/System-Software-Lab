#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    struct flock lock;
    char buf[10];
    int fd;
    fd=open("file6.txt", O_RDONLY|O_CREAT);
    lock.l_type=F_RDLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid = getpid();
    printf("\nBefore entering read mode CS");
    fcntl(fd, F_SETLKW, &lock);

    printf("\nInside read mode CS");
    int i=read(fd, &buf, 10);
   
    printf("\nEnter to unlock..");
    getchar();
    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);



    fd=open("file6.txt", O_WRONLY| O_CREAT);

    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid = getpid();
    printf("\nBefore entering write mode CS");
    fcntl(fd, F_SETLKW, &lock);

    printf("\nInside write CS");
    write(fd, "Hello World", 15);
    printf("\nEnter to unlock..");
    getchar();
    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
}