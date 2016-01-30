#include<stdio.h>
#include<errno.h>
#include<pthread.h>
 	void *handler(void *arg)
	{
	printf("arg :%d\n",*((int*)arg));
	while(1)
	{
	
	sleep(1);
	printf("hello world\n");
	}
	
	}
 int main(int argc, const char *argv[])
 {
int num=10;
int a=1234;
pthread_t thread;
if((pthread_create(&thread,NULL,handler,(void*)&a))==-1)
{	perror("pthread_create");
return -1;
}

while(num--)
{
sleep(1);
	printf("main \n");

}
 	return 0;
 }

