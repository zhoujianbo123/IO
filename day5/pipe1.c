#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
	pid_t pid;
	int fd[2];
	char buf[64] = {0};
	if(pipe(fd) == -1)
	{
		perror("pipe");
		return -1;
	}
	if((pid = fork()) == -1)
	{
		perror("fork");
		return -1;
	}
	if(pid == 0)
	{
		close(fd[1]);
		while(1)
		{
			read(fd[0],buf,sizeof(buf));
			printf("receive : %s",buf);
		}
	}
	else
	{
		close(fd[0]);
		while(1)
		{
			puts("input > ");
			fgets(buf,sizeof(buf),stdin);
			write(fd[1],buf,sizeof(buf));
		}
	}

	return 0;
}
