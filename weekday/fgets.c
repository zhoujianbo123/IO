#include<stdio.h>
#include<string.h>
 int main(int argc, const char *argv[])
 {
 	FILE *fp;
	int n;
	int line=0;
	char buf[128]={0};
	if(argc !=2)
	{
	printf("error input");
	return -1;
	}

	if((fp=fopen(argv[1],"r+"))==NULL)
	{
	printf("error open");
		return -1;
	
	}
	while((fgets(buf,128,fp))!=NULL)
	{
	if(buf[strlen(buf)-1]=='\n')
		line++;
	}
	printf("%d\n",line);
	printf("%s",buf);
 	return 0;
 }
