#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc, const char *argv[])
{  
	pid_t pid;
	if((pid=fork())==-1)
	{
		perror("frok");
		return -1;
	}
	char buf[128];
	int dsc;
	if((dsc=open("file",O_RDONLY))<0)
	{
		perror("open");
		return -1;
	}
	if(pid==0)
	{
		int fd1;
		if((fd1=open("file1",O_RDONLY|O_CREAT|O_EXCL,0666))<0)
		{
			perror("open");
			return -1;
		}
		int i;
		while((i=read(dsc,buf,sizeof(buf)))>0)
		{
			write(fd1,buf,i);
		}
		close(fd1);
		close(dsc);
	}




	if(pid>0)
	{
		sleep(1);
		int fd2;
		int sta;
		wait(&sta);
		if((fd2=open("file2",O_RDONLY|O_CREAT|O_EXCL,0666))<0)
		{
			perror("open");
			return -1;
		}
		int m;
		while((m=read(dsc,buf,sizeof(char)))>0)
		{
			write(fd2,buf,m);
		}
		close(fd2);
		close(dsc);
		
	}

	return 0;
}
