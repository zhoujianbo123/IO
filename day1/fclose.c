#include<stdio.h>

 int main(int argc, const char *argv[])
 {
	 FILE * fl;
 	int num=0;
	fclose(stdin);
	while ((fl=fopen("file","r"))!=NULL)
	{
	num++;
	}
	printf("%d\n",num);
 	return 0;
 }
