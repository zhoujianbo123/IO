#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
 int main(int argc, const char *argv[])
 {
 	pid_t  pid;
	pid=fork();
	if(pid==-1)
	{
	perror("fork");
	exit(0);
	
	}

	if(pid==0)
	{
	printf("I am a boy\n");
	printf("me ID:%d \n",getpid());
	printf("father ID is %d\n",getppid());
	exit(0);
	}

	if(pid>0)
	{
		sleep(1);
	printf("baby is borned\n");
    fprintf(stdout,"my ID is %d \n",getpid());
	}

 	return 0;
 }
