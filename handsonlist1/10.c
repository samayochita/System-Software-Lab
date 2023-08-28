#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
 int main()
 {
    int fd, i,j;
    char line1[10]=" Half";
    char line2[10]="Other half";
    fd=open("file3.txt", O_RDWR | O_CREAT);
    write(fd, line1, 10);
    
    i=lseek(fd, 10, SEEK_CUR);
    write(fd, line2, 10);
    printf("\n Return value of lseek() is %d", i);
    return 0;
 }