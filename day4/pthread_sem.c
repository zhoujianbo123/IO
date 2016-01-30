#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t thread1,thread2;
sem_t sem;
char buf[64] = {"xxx"};


void *handler1(void *arg)
{
	while(1)
	{
		fgets(buf,sizeof(buf),stdin);
		sem_post(&sem);
	}
	pthread_exit("handler1");
}
void *handler2(void *arg)
{
	while(1)
	{
		sem_wait(&sem);
		printf("%s\n",buf);
	}
	pthread_exit("handler2");
}


int main(int argc, const char *argv[])
{
	if(pthread_create(&thread1,NULL,handler1,NULL) == -1)
	{
		perror("create thread1");
		return -1;
	}
	if(pthread_create(&thread2,NULL,handler2,NULL) == -1)
	{
		perror("create thread2");
		return -1;
	}

	if(sem_init(&sem,0,0) == -1)
	{
		perror("sem init");
		return -1;
	}

//	sem_post(&sem); 
//	sem_wait(&sem);
#if 0
	int n = 0;
	sem_getvalue(&sem,&n);
	printf("n = %d\n",n);
#endif

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	return 0;
}
