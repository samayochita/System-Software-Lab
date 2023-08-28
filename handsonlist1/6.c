#include<unistd.h>
#include<stdio.h>
int main()
{
    int i;
    int count=10;
    int buf[10];
    i=read(0, buf, count);
    printf("\nValue of i: %d \n ", i);
    write(1, buf, count);
    return 0;
}

