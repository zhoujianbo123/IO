#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/stat.h>

pthread_t thread;
pthread_mutex_t lock;
int value1,value2;

void *handler(void* arg)

{
int i=100;
	while(i--)
	{
#if 0
		pthread_mutex_lock(&lock);
		if(value1!=value2)
		{
			sleep(1);
			printf("value1=%d value2=%d\n",value1,value2);
		}
		pthread_mutex_unlock(&lock);
#endif
		sleep(2);
		printf("%d \n",i);

	}


}



int main(int argc, const char *argv[])
{
	pthread_t thread;
	pthread_mutex_init(&lock,NULL);
	if(pthread_create(&thread,NULL,handler,NULL)==-1)
	{
		perror("create thread");
		return -1;

	}
	while(1)
	{
		pthread_mutex_lock(&lock);
		value1++;
		value2++;
		pthread_mutex_unlock(&lock);

	}
	pthread_join(thread,NULL);


	return 0;
}
