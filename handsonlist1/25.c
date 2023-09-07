#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <stdlib.h>
int main()
{
    pid_t child_pid, wpid;
    int status=0;
    for(int id=0;id<3;id++)
    {
        if((child_pid=fork())==0)
        {
            exit(0);
        }
    }
    while ((wpid = wait(&status)) > 0); // this way, the father waits for all the child processes 
 
}