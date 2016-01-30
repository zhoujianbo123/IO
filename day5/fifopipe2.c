#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
int main(int argc, const char *argv[])
{
	int fd;
	int fd1;
	int n;
	char buf[64];
	if((fd1=open("file1",O_WRONLY|O_CREAT,0666))>0)
	{
		if((fd=open("fifo",O_RDONLY))<0)
		{
			perror("open");
			return -1;

		}
		while((n=read(fd,buf,sizeof(buf)))>0)
		{
			write(fd1,buf,n);
		}
	}
	putchar(10);
	return 0;
}
