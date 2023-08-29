#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  

int main()
{
  
    
    int fd = creat("foo.txt", 0644);
    if (fd == -1 ) {
        perror("FAILED");
        return 1;
    }
  printf(" File '%s' is created with file descriptor %d\n", "foo.txt",fd);
  close(fd);
  return 0;
  }
