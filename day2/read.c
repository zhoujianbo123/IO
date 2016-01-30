#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

 int main(int argc, const char *argv[])
 {
 	int fd;
	char buf[64]={0};
	int n=0;
	if((fd=open("file",O_RDONLY))==-1)
	{
	perror("open");
	return -1;
	
	}
	n=read(fd,buf,sizeof(buf));
	printf("n=%d \n",n);
	printf("%s\n",buf);
	putchar(10);
 	return 0;
 }

