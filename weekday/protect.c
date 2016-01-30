#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
 int main(int argc, const char *argv[])
 {
	 char buf[64]={0};
 	pid_t pid;
int i;
	if((pid=fork())<0)
	{
	perror("fork failed");
	exit(1);
	}
	if(pid==0)
	{
	sleep(1);
	chdir("/tmp");
   umask(0);
	
	for(i=0;i<getdtablesize();i++)
	{
	close(i);
	}
fgets(buf,sizeof(buf),stdin);

printf("%s\n",buf);
	
	}
	else
exit(0);	
 	return 0;
 }
