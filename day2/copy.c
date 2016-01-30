#include<stdio.h>
 int main(int argc, const char *argv[])
 {
	 FILE *fp,*fq;
	 char a[64];
	 int n;
 	if(argc!=3)
	{
	printf("error input");
	return -1;
	}
if((fp=fopen(argv[1],"r"))==NULL)
{

printf("open failed");
return -1;
}
if((fq=fopen(argv[2],"a+"))==NULL)
{

printf("open failed");
return -1;
}

while((n=fread(a,sizeof(char),64,fp))>0)
{
fwrite(a,sizeof(char),n,fq);
}
fclose(fq);
fclose(fp);


 	return 0;
 }
