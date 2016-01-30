#include<stdio.h>
 int main(int argc, const char *argv[])
 {
   char a;
FILE *lq;
  lq=fopen("file","r");
 a= getc(lq);
  printf("%c\n",a);
  a=getc(lq);
  printf("%c\n",a);

 	return 0;
 
