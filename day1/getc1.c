#include<stdio.h>
 int main(int argc, const char *argv[])
 {
	 char a;
 	FILE *sp;
	sp=(fopen("file","r"));
	a=getc(sp);   //返回值虽是整形
	              // 但将它以字符输出
  putchar(a);
  putchar(10);
  printf("%c",a);
 	return 0;
 }
