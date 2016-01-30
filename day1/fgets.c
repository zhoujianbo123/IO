#include<stdio.h>

 int main(int argc, const char *argv[])
 {
	 FILE *p;
 	char a[64]={0};
	if((p=fopen("file","r+"))==NULL)
	{
	printf("open failed\n");
	return -1;
	
	}
	fgets(a,7,p);

    if(feof(p))
	{
	printf("succe
			]<F6>ss");
	}
	printf("%s \n",a);
 	return 0;
 }
