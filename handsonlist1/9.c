#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<time.h>

void printfileinfo(struct stat stats)
{
struct tm dt;
printf("\nFile size: %lld", stats.st_size);
dt= *(gmtime(&stats.st_ctime));
printf("\nCreated on : %d-%d-%d %d:%d:%d ", dt.tm_mday, dt.tm_mon , dt.tm_year+1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
dt= *(gmtime(&stats.st_atime));
printf("\nAccessed on : %d-%d-%d %d:%d:%d ", dt.tm_mday, dt.tm_mon , dt.tm_year+1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
dt= *(gmtime(&stats.st_mtime));
printf("\nModified on : %d-%d-%d %d:%d:%d ", dt.tm_mday, dt.tm_mon , dt.tm_year+1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
printf("\nThe optimal I/O block size for the file is %d", stats.st_blksize);
printf("\nThe number of blocks allocated for the file in 512 Byte units is %lld", stats.st_blocks);
printf("\nUser ID of the file is %d", stats.st_uid);
printf("\nGroup ID of the file is %d", stats.st_gid);
printf("\nMode of File is %d", stats.st_mode);
printf("\nThe Inode number is %lld", stats.st_ino);
printf("\nNumber of Hard Links is %d", stats.st_nlink);

}
int main()
{
    char path[100];
    struct stat stats;
    printf("Enter source file path:");
    scanf("%s", path);
    if(stat(path, &stats)==0)
        printfileinfo(stats);

    else{
        printf("Unable to get file information\n");
        printf("Please check if '%s' file exists", path);
    }
    return 0;
}