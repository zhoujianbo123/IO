#include<stdio.h>
#define N 128
 int main(int argc, const char *argv[])
 {
 	struct me{
	long type;
	char data[128];
	};
	struct me lg;

	printf("%d\n",sizeof(lg));
	printf("%d\n",sizeof(lg.data));
 	return 0;

 }
