#include<stdio.h>
#include"ipc.h"
#include<fcntl.h>
int main(int argc, const char *argv[])
{
	int fd1,fd2;
	char buf[1024];
	int n;
	if (argc!=2)
	{
		printf("opreat error\n");
		return -1;
	}
	if((fd1=open(argv[1],O_RDONLY))<0)
	{
		perror("open");
		exit(1);

	}		
	if(mkfifo("fifo",0666)<0)
	{
		perror("mififo");
		exit(1);
	}
	if(fd2=open("fifo",O_WRONLY)<0)
	{
		perror("open fifo");
		exit(-1);
	}
	while((n=read(fd1,buf,sizeof(buf)))>0)
	{
		write(fd2,buf,n);

	}


	return 0;
}
