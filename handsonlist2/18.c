#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
        if(!fork()){
            dup2(fd1[1],1);
            close(fd1[0]);
            close(fd2[0]);
            close(fd2[1]);
            execlp("ls", "ls", "-Rl", (char *)NULL);
        }
        else{
            if(!fork()){
                dup2(fd1[0], 0);
                dup2(fd2[1], 1);
                close(fd1[1]);
                close(fd2[0]);
                execlp("grep", "grep", "^d", (char *)NULL);
            }
            else{
                dup2(fd2[0], 0);//redirects the standard input to the read end of the pipe.
                // This means that any input that the program would normally read from the keyboard (stdin) will now come from the data written to the pipe by another process. 
                close(fd2[1]);
                close(fd1[0]);
                close(fd1[1]);
                execlp("wc", "wc", "-l", (char *)NULL);
            }
        }
}