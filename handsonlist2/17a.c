#include<stdio.h>
#include<unistd.h>
int main()
{
    int fd[2];
    pipe(fd);
    if(!fork()){//child
        close(1);//close stdout
        close(fd[0]);//Closes the read end of the pipe in the child process.
        dup(fd[1]);//redirects the standard output to the write end of the pipe
        execlp("ls", "ls", "-l", (char *)NULL);//Replaces the child process with the ls -l command
    }
    else{//parent
        close(0);//close stdin
        close(fd[1]);//Closes the write end of the pipe in the parent process.
        dup(fd[0]);//Duplicates the file descriptor fd[0] to the lowest available file descriptor, which is 0 (stdin).redirects the standard input to the read end of the pipe.
        execlp("wc", "wc", (char *)NULL);
    }
}