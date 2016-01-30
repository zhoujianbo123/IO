#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
 int main(int argc, const char *argv[])
 {
	 pid_t pid;
	 if((pid =fork())==-1)
	 {
	perror("fork");
	exit(0);
	
	 }
 	if(pid==0)
	{
	printf("child :\n");
	printf("PID: %d\n",getpid());
	puts("child exit");
	exit(1);
	}
	else
	{
		sleep(1);
#if 1
	int status,n;

n= wait(&status);
	printf("parent :\n");
	printf("me Id %d\n:",getpid());
	printf("status=%d\n",status);
	printf("n=%d \n",n);
#endif
	while(1);	
	}
 	return 0;
 }
