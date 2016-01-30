
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
int main(int argc, const char *argv[])
{
	pid_t pid;

	if((pid=fork())==-1)
	{
		perror("fork");
		exit(1);
	}

	if(pid==0)
	{	FILE *fp;
		int i=0;
		int j=0;
		sleep(1);
		setsid();
			chdir("/");
		umask(0);
		for(i=0;i<=getdtablesize();i++)
			close(i);
		if((fp=fopen("file2","a+"))==NULL)
		{
			perror("fp");
			exit(1);

		}
		j=0;
		while(1)
		{

			sleep(3);
			fprintf(fp,"%d hello world!\n",j++);
             fflush(fp);
		}

	}

	else
	{
		printf("parent\n");
exit(0);
	
	}
	return 0;
}
