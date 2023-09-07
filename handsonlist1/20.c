#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<sys/resource.h>
int main()
{
  
    int pri=getpriority(PRIO_PROCESS, 0 );
    printf("Current priority: %d", pri);
    nice(4); // To set level 4 as nice value to currenst process
    
    pri =getpriority(PRIO_PROCESS, 0 );
    printf("\nNew Priority: %d", pri);

}