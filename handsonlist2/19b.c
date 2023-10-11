#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
int main(){
    int fd;
    fd=mkfifo("myfifo", 0744);
    printf("fd= %d\n", fd);
}