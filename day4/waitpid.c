#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>

 int main(int argc, const char *argv[])
 {
    pid_t pid;
if((pid=fork())==-1)
{
perror("fork");
return -1;

}

if(pid==0)
{
 	int num=5;
	printf("child :\n");
	while(num--)
	{
	sleep(1);
	printf("sleep %d\n",num);
	}

	exit(0);
}
	else
	{
	int ret=0;
	while((ret=waitpid(-1,NULL,WNOHANG))==0)
	{
	sleep(1);
	printf("wait child\n");

	}
	puts("wow child exit");

	
	}
 	return 0;
 }
