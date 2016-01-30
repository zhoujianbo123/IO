#include<stdio.h>
 int main(int argc, const char *argv[])
 {
	 int a;
 	FILE *fp;
	if((fp=fopen("good","r"))==NULL)
	{
		printf("error open");
		return -1;
			
	}
a=getc(fp);
	putc(a,stdout);
	putchar(10);
 	return 0;
 }
