
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
pthread_exit("112");
}




 int main(int argc, const char *argv[])
 {
 	pthread_t thread;
if(pthread_create(&thread,NULL,handler,NULL)==-1)

{
perror("thread_create");
return -1;

}
puts("main hello world");
pthread_exit("llll");
 }
