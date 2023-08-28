#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>
#include<stdlib.h>


int main()
{
    int retval;
    struct timeval tmo;
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    tmo.tv_sec=10;
    tmo.tv_usec=0;

    retval=select(1,&readfds, NULL, NULL, &tmo);
    if(retval)
        printf("Data is available within 10 sec\n");
    
    
    else
        printf("Data isn't available within 10 sec\n");
   
    return 0;


}