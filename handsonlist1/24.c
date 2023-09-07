#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int pid= fork();
    if(pid>0)   
        printf("In parent process");
    
    else if(pid==0)
    {
        sleep(30);
        printf("In child process");
    }
    return 0;
}