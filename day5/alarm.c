#include<stdio.h>
#include<unistd.h>
 int main(int argc, const char *argv[])
 {
	 int i=4;
 	alarm(5);
	pause();
	while(i--)
	{
		sleep(1);
	printf("%d\n",i);
	}
 	return 0;
 }
