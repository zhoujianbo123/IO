#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
 int main(int argc, const char *argv[])
 {
 	char buf[6];

	fgets(buf,7,stdin);
	printf("%s",buf);

 	return 0;
 }
