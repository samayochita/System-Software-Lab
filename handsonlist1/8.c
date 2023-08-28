#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
    char line[200];
    memset(line, '\0', sizeof(line));
    int fd;
    char buf;
    fd=open("file2.txt", O_RDONLY);
    int i, n=0;
    i=read(fd, &buf,1);
    while(i!=0)
    {
        if(buf==10)
        {
            printf("\n %s", line);
            n=0;
            memset(line, '\0', sizeof(line));

        }
        else{
            line[n++]=buf;

        }
        i=read(fd, &buf,1);
    }
    
    
return 0;
}