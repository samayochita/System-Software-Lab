#include<unistd.h>
#include<stdio.h>

int main(){
    int fd[2];
    char buf[7];
    pipe(fd);
     
    write(fd[1], "Hello\n", 7);
   read(fd[0], buf, sizeof(buf));
   printf("Read from pipe: %s\n", buf);
}