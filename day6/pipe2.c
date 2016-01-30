#include<stdio.h>
#include"ipc.h"
int main(int argc, const char *argv[])
{
	int fd[2];
	pid_t pid;
	char buf[1024];
	if(pipe(fd)<0)
	{
		perror("pipe");
		return -1;
	}
	if((pid=fork())<0)
	{

		perror("fork");
		return -1;
	}

	if(pid==0)
	{
		while(1)
		{
		sleep(1);
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		puts(buf);

		}
	}
	else
	{
			close(fd[0]);
		while(1)
		{
			fgets(buf,sizeof(buf),stdin);
			write(fd[1],buf,sizeof(buf));
		}
	}
	return 0;
}
