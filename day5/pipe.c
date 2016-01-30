#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/stat.h>

 int main(int argc, const char *argv[])
 {
 	int fd[2];
	char buf[]="hello world";
	char buf2[64];
int num;
   pipe(fd);
num=write(fd[1],buf,sizeof(buf));
printf("%d\n",num);
read(fd[0],buf2,num);
printf("%s",buf2);
 	return 0;
 }
