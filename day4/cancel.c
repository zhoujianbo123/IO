
#include<stdio.h>
#include<errno.h>
#include<pthread.h>
pthread_t thread1,thread2;
 void* handler1(void*argc)
{
int i=5;
while(i--)
{
	sleep(1);
printf("i will rock you\n");

}
pthread_exit("quit");
}
 void* handler2(void*argc)
{
int i=3;
while(i--)
{
	sleep(1);
printf("i will beat you\n");

}
pthread_cancel(thread1);
pthread_exit("quit");
}

 int main(int argc, const char *argv[])
 {
	 char *buf;
pthread_t thread;
if(pthread_create(&thread1,NULL,handler1,NULL)==-1)

{
perror("thread_create");
return -1;

}
if(pthread_create(&thread,NULL,handler2,NULL)==-1)

{
perror("thread_create");
return -1;

}
pthread_join(thread1,NULL);
puts("-------A------------");
pthread_join(thread2,NULL);

puts("main hello world");
 	
 	return 0;
 }
