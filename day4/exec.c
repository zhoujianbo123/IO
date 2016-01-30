#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>

 int main()
 {
 	printf("exec :\n");
#if 0
	if(execl("/bin/ls","ls","-l","-a",NULL))
	{
	perror("execl");
	}


	if(execlp("ls","ls","-l","-a",NULL))
	{
	perror("execlp");
	}
#endif

	char *argv[]={"ls","-la",NULL};
	if(execv("/bin/ls",argv)==-1)
	{
	perror("execlv");
	
	}
 	return 0;
 }
