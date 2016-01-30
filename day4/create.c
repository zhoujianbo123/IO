#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
void *handler(void *argv)
{
int i=5;
while(i--)
{
	sleep(2);
printf("i will rock you !\n");
}
pthread_exit("123");

}

 int main(int argc, const char *argv[])
 {

 pthread_t thread;
 if(pthread_create(&thread,NULL,handler,NULL)==-1)
 {
 perror("pthread_create");
 return -1;
 }
 //pthread_join(thread,NULL);
 int j=10;
 while(j--)
 {
	 sleep(2);
 printf("%d wait ...\n",j);
 }
 pthread_exit("321");
 	return 0;
 }

