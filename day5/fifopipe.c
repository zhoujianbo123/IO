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
	int r;
	char buf[64];
	if((fd1=open("file3",O_RDONLY|O_CREAT,0666))<-1)
	{
	perror("open");
	return -1;
	}

if((fd=open("fifo",O_WRONLY))<0)
{
perror("open");
return -1;

}
	while((r=read(fd1,buf,sizeof(buf)))>0)
    {

	  write(fd,buf,r);
    }
return -1;
}
