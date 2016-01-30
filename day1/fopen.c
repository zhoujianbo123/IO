#include<stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp=NULL;
	if((fp=fopen("file","w"))==NULL)
	{
	printf("fopen error");
	
	return -1;
	}

	fprintf(fp,"hello world !");
	return 0;
}
