#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
int fd;
while((fd=open("happy",O_RDWR|O_CREAT,0666))!=-1)
{
	printf("fd=%d",fd);
}
return 0;
}
