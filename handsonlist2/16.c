#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
    char buff[80],buff1[80];
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
        if(!fork())
        {
            close(fd1[0]);
            printf("Enter message to the Parent:");
            scanf("%[^\n]", buff);
            write(fd1[1], buff, sizeof(buff));
            close(fd2[1]);
            read(fd2[0], buff1, sizeof(buff1));
            printf("Message from Parent: %s\n", buff1);
        }
        else{
            close(fd1[1]);
            read(fd1[0],buff,sizeof(buff));
            printf("Message from Child: %s\n", buff);
            close(fd2[0]);
            printf("Enter message to the Child:");
            scanf(" %[^\n]", buff1);
            write(fd2[1], buff1, sizeof(buff1));

        }
wait(0);

} 