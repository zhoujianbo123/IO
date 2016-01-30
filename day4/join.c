#include<stdio.h>
#include<errno.h>
#include<pthread.h>
 void* handler(void*argc)
{
int i=5;
while(i--)
{
printf("i will rock you\n");

}
pthread_exit("quit");
}

 int main(int argc, const char *argv[])
 {
	 char *buf;
pthread_t thread;
if(pthread_create(&thread,NULL,handler,NULL)==-1)

{
perror("pthread_create");
return -1;

}
pthread_join(thread,(void**)&buf);
	printf("%s\n",buf);

puts("main hello world");
 	
 	return 0;
 }
