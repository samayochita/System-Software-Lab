#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sched.h>
#include<unistd.h>
int main(){
   struct sched_param  params;
      
   int pid = getpid();
   int policy= sched_getscheduler(pid);
   printf("Current Scheduling Policy: %d\n", policy);
    params.sched_priority = 80;

 if(sched_setscheduler(pid, SCHED_FIFO, &params) == -1){
        perror("Scheduling policy cannot be set");
    }
    int new_policy = sched_getscheduler(pid);
    printf("Modified Scheduling policy: %d\n", new_policy);

    return 0;

}