#include<stdio.h>
 int main(int argc, const char *argv[])
 {
	 FILE *lp,*lq;
	 char a[64]={1};
 	if(argv!=3)
	{	printf("input error");
		return -1;
	}
if((lp=fopen(argv[1],"r"))==NULL)
{
	printf("open %s error",argv[1])

 	return 0;
 }
