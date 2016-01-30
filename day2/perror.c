#include<stdio.h>
 int main(int argc, const char *argv[])
 {
 	FILE *fq=NULL;
	if((fq=fopen("day","r"))==NULL)
	{
	
	perror("fopen");
return -1;	
	}

 	return 0;
 }
