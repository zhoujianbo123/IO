#include<stdio.h>
int main(int argc, const char *argv[])
{
	int pid;
	int fd[2];
	char buf[64];
pipe(fd);
	pid=fork();
	if(pid==-1)
	{
		perror("fork");
		return -1;
	}
	if(pid==0)
	{
		close(fd[1]);

		while(1)
		{
			read(fd[0],buf,sizeof(buf));
			printf("%s",buf);
		}
	}
	if(pid>0)
	{
		close(fd[0]);
		while(1)
		{
			printf("this is a parent\n");
			fgets(buf,sizeof(buf),stdin);
			write(fd[1],buf,sizeof(buf));
			sleep(2);
		}
	}
	return 0;
}
