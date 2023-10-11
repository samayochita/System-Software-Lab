#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
    char buf[8];
    int fd[2];
    
    pipe(fd);

    if(fork()){
        close(fd[0]);//close the read end of the pipe
        printf(("Enter message to the child:"));
       
        scanf(" %7[^n]", buf);
        write(fd[1], buf, sizeof(buf));
    }
    else{ 
        close(fd[1]);//close the write end of the pipe
         getchar();
        read(fd[0], buf, sizeof(buf));
        printf("Message from parent: %s\n", buf);
    }
    wait(0);
}
