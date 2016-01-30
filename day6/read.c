#include<stdio.h>
#include"ipc.h"
#include<fcntl.h>
int main(int argc, const char *argv[])
{
	int fd3,fd4;
	char buf[1024];
	int n;
	if (argc!=2)
	{
		printf("opreat error\n");
		return -1;
	}
	
#if 0
	if((fd1=open(argv[1],O_RDONLY))<0)
	{
		perror("open");
		exit(1);

	}	
#endif
	if(mkfifo("fifo",0666)<0)
	{
		if(errno=EEXIST)
		{
	perror("fifo also exist");
		
		}
		else
		{
		perror("mififo");
		exit(1);
	}
	
	}
	if((fd3=open("file2",O_WRONLY|O_CREAT,0666))<0)
	{
		perror("open");
		exit(1);

	}		
	if(fd4=open("fifo",O_RDONLY)<0)
	{
		perror("open fifo");
		exit(1);
	}
	while((n=read(fd4,buf,sizeof(buf)))>0)
	{
		write(fd3,buf,n);
//	fprintf(stdout,"%s",buf);
	}


	return 0;
}
