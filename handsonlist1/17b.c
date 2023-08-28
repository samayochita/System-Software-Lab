#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
int main()
{
    struct{
        int ticket_no;
    }db;
    struct flock lock;
    int fd;
    db.ticket_no=0;
    fd=open("db.txt", O_RDWR);
    // read(fd, &db, sizeof(db));
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();
    printf("\nBefore entering critical section");
    fcntl(fd, F_SETLKW, &lock);
    read(fd, &db, sizeof(db));
    printf("\nCurrent ticket Number: %d", db.ticket_no);
    db.ticket_no++;
    lseek(fd, 0L, SEEK_SET );
    printf("\nInside the critical section.. ");
    printf("\nEnter to unlock..");
    write(fd, &db, sizeof(db));
    getchar();
    lock.l_type=F_UNLCK;
    printf("unlocked\n");
    fcntl(fd, F_SETLK, &lock);
    printf("finish\n");
    return 0;

}