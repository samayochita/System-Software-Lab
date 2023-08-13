#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){

int l=link( "dest", "destHL" );
	if(l<0){
	perror("FAILED"); return 1;}
int s=symlink("dest", "destSL");
	if(s<0){perror("FAILED");return 1;}

int e =mknod("destFIFO", S_IFIFO, 0);

if(e<0)
{
perror("Failed"); 

}

return 0;
}
