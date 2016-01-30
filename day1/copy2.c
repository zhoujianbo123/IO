#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#define N 1024
 int main(int argc, const char *argv[])
 {
 	FILE *A;
	FILE *B;
char buf[N];
int n,m;
	if((A=fopen("file","r"))==NULL)
	{
	printf("errno fopen");
	return -1;
	}
	

	if((B=fopen("file2","a+"))==NULL)
	{
	printf("errno fopenB");
	return -1;
	}

while((n=fread(buf,sizeof(char),N,A))>0)
{
fwrite(buf,sizeof(char),n,B);

}
 	return 0;
 }
