#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc, char *argv[]){
    struct stat stats;


    stat(argv[1], &stats);
    printf("\nFile Mode is %d", stats.st_mode);
    if(stats.st_mode == S_IFDIR)
        printf("\nFile Type is: Directory\n");
    else if(stats.st_mode == S_IFCHR)
        printf("\nFile Type is Character device\n");
    else if(stats.st_mode == S_IFREG)
        printf("\nFile Type is Regular file\n");
    else if(stats.st_mode == S_IFLNK)
        printf("\nFile Type is Symbolic Link\n");
    else if(stats.st_mode == S_IFSOCK)
        printf("\nFile Type is Socket\n");
    else if(stats.st_mode == S_IFBLK)
        printf("\nFile Type is Block device\n");
   else if(stats.st_mode == S_IFIFO)
        printf("\nFile Type is FIFO\n");
    

}
