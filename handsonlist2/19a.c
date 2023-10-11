#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
    int fd;
    fd=mknod("myfifo", S_IFIFO|0744, 0);
    printf("fd= %d\n", fd);
}