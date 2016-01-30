#include<stdio.h>
#include<errno.h>
 int main(int argc, const char *argv[])
 {
 	FILE *fd;
	FILE *fd1;
	if((fd=fopen("file","r+"))==NULL)
	{
	perror("freopen");
	return -1;
	
	}

    if((fd1=freopen("good","a+",fd))==NULL)
	{
	
	perror("freopen");
	return -1;
	}
   
fprintf(fd,"hello monday");
 	return 0;
 }
