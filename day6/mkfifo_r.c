#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define N 64

int main(int argc, const char *argv[])
{
	int fd,fd_file;
	char buf[N] = {0};
	int n;

	if(mkfifo("fifo",0666) == -1)
	{
		if(errno == EEXIST)
		{
			printf("fifo exist\n");
		}
		else{
			perror("mkfifo");
			return -1;
		}
	}
	if((fd = open("fifo",O_RDONLY)) < 0)
	{
		perror("open fifo");
		return -1;
	}
	if((fd_file = open(argv[1],O_WRONLY | O_CREAT,0666)) < 0)
	{
		perror("open file");
		return -1;
	}

	while((n = read(fd,buf,sizeof(buf))) > 0)
	{
		write(fd_file,buf,n);
	}

	return 0;
}
