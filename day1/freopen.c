#include<stdio.h>
 int main(int argc, const char *argv[])
 {
 	FILE *fp,*fp1,*q;
	if((fp=fopen("night","r"))==NULL)
	{
	printf("error fopen");
	return -1;
	}
	
	if((fp1=freopen("good","a+",fp))==NULL)
	{
	printf("error freopen");
	return -1;
	
	}
	fprintf(fp,"wan an night");
return 0;
 }
