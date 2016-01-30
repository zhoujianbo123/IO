#include<stdio.h>
 int main(int argc, const char *argv[])
 {
 	char a[15];
	fprintf(stdout,"hello world\n");  //将字符输出到屏幕上

	sprintf(a,"5 ");          //将字符串输出到字符数组中 
	sprintf(a+2,"%d \n",6);
	printf("%s",a);          //默认将字符串输出到屏幕上



 	return 0;
 }
