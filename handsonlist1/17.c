#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
    struct{
        int ticket_no;
    }db;
   
    int fd;
    db.ticket_no=0;
    fd=open("db.txt", O_RDWR);
    int ticket_count=0;
    int x=write(fd, &ticket_count, sizeof(db.ticket_no));
    printf("%d\n", x );
   
   
    
    close(fd);
    return 0;
}