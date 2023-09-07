#include <unistd.h>
#include <stdio.h>
int main(){
	char * envp[] = { NULL};	
    execlp("ls","ls","-l","-Rl", NULL);
	execl("/usr/bin/ls","ls","-Rl",NULL);
	execle("/usr/bin/ls","ls","-Rl",NULL,envp);
	char *arg[5];
	arg[0]="ls";
	arg[1]="-l";
	arg[2]="-R";
	arg[3]=NULL;
	execv("/usr/bin/ls",arg);
	execvp("/usr/bin/ls",arg);
	

}