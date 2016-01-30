#include<stdio.h>
 int main(int argc, const char *argv[])
 {
 	FILE *fq;
	char b[64]="hello world";
	char a[64]={0};
	int i,m,k;
if((fq=fopen("file","a+"))==NULL)
{
printf("error open");
return -1;
}
m=fwrite(b,sizeof(char),32,fq);

	printf("m=%d \n",m);
	rewind(fq);
k=fread(a,sizeof(char),64,fq);
   printf("k=%d \n",k);

printf("%s",a);
putchar(10);
 	return 0;
 }
