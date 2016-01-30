#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
 pthread_t pthread1,pthread2;
 sem_t sem;
char buf[1024];
void *handle1(void *arg)
{
fgets(buf,sizeof(buf),stdin);
 sem_post(&sem);
}
void *handle2(void *arg)
{
sem_wait(&sem);
puts(buf);
fflush(stdout);
}

  int main(int argc, const char *argv[])
  {
  	if(pthread_create(&pthread1,NULL,handle1,NULL)==-1)
	{
	perror("create thread1");
	exit(1);
	}
  	if(pthread_create(&pthread2,NULL,handle2,NULL)==-1)
	{
	perror("create thread2");
	exit(1);
	}
sem_init(&sem,0,0);
// pthread_join(pthread2,NULL);
sem_destroy(&sem);
  	return 0;
  }  
