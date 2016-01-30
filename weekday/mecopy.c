#include<stdio.h>
 int main(int argc, const char *argv[])
 {
	 FILE *fp,*fq;
int n,m;
	 char buf[1024];
 	if(argc!=3)
	{
	printf("operation error!");
	return -1;
	
	}
if((fp=fopen(argv[2],"r"))==NULL)
{
printf("%s open failed",argv[2]);
return -1;

}

if((fq=fopen(argv[1],"a+"))==NULL)
{
printf("%s open failed",argv[1]);
return -1;
}

while((n=fread(buf,1,64,fp))>=0)
		{
		
		fwrite(buf,sizeof(char),n,fq);
			printf("%d\n",n);
		}
 	return 0;
 }
