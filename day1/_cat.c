#include<stdio.h>
 int main(int argc, const char *argv[])
 {
 	FILE *fp;

	char ch;

	if(argc<2)
	{
	
	printf("error");
	}
	if((fp=(fopen(argc[1],"r+")))==NULL)
	{
	printf("open error");
	return -1;
	}
while((ch=getc(fp))!=EOF)
{
printf("%c",ch);

}

 	return 0;
 }
