#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/time.h>
#include <sys/wait.h>


int main( int argc, char *argv[] ){

    pid_t pid;

    int fd=open("file2.txt", O_RDWR|O_CREAT, 0777);
    pid = fork();

    if( pid > 0 ){ // parent process
    char buff[20]="\nHello I'm parent";
    write(fd, &buff, sizeof(buff));    
    }
    else{

    char buff[20]="\nHello I'm child";
    write(fd, &buff, sizeof(buff));
    
    }
    
    return 0;
}