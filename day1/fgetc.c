#include<stdio.h>
 int main(int argc, const char *argv[])
 {
   char a;
   int n=0;
   FILE *fq;
   if((fq=fopen("good","r"))==NULL)
   {
   printf("open failed");
   return -1;
   
   }
   while((a=getc(fq))!=EOF)
   {
	 if(a=='\n')
	 {
	 n++;
	 }
   
   }
   
printf("%d",n+1);
 	return 0;
 }
