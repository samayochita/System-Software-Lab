#include<stdio.h>
#include<sys/types.h>

#include<unistd.h>

void forkexample()
{
    
    if(fork()==0)
        printf("\nProcess ID of Child: %d", getpid());
    else   
        printf("\nProcess ID of Parent: %d", getpid());
}
int main()
{
    forkexample();
    return 0;
}