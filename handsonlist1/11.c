#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
        int fd1, fd2;
        char text[10]="Hello";
        fd1=open("file1.txt", O_RDWR|O_CREAT, 0744);
        fd2=dup(fd1);


        write(fd1,text, 10);
        write(fd2, text, 10);
        printf("the values of fd1 and fd2 are: %d and %d", fd1, fd2);
        close(fd1);  
        dup2(fd2, fd1);
        
        write(fd1, text , 10);
        printf("\nValues of fd1 and fd2  are : %d and %d", fd1, fd2);
        close(fd1);

       
        fd1=fcntl(fd2, F_DUPFD, 0);
        write(fd1,text,10);
        printf("\nValues of fd1 and fd2  are : %d and %d", fd1, fd2);
        return 0;
 
}       


 

