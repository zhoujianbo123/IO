#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#define ROAD "/mnt/hgfs/share/"
int main(int argc, const char *argv[])
{
	int fq,fp,n;
	char a[25];
	char buf[1024]={0};
	while(1)
	{
		char file[64]=ROAD;
		printf("please the name of song:");

		scanf("%s",a);
		if(strncmp(a,"quit",4)==0)
		{
			printf("bye !");
			break;

		}
		strcat(file,a);
		printf("please wait : \n");
		if((fp=open(file,O_RDONLY))==-1)
		{

			printf("error open");
			return -1;
		}
		if((fq=open(a,O_RDWR |O_CREAT|O_TRUNC),0776)==-1)
		{

			printf("error open2");
			return -1;
		}

		while((n=read(fp,buf,sizeof(buf)))>0)
		{

			write(fq,buf,n);
	

		}
       printf("%s download over \n",a);
	}

	close(fp);
	close(fq);
	return 0;
}
