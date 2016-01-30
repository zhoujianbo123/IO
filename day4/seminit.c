
#include<stdio.h>
#include<errno.h>
#include<pthread.h>
#include<semaphore.h>
pthread_t thread1,thread2;
sem_t sem;
char buf[64]={"0"};
 void* handler1(void*argc)
{
while(1)
{
	sleep(1);
fgets(buf,sizeof(buf),stdin);
sem_post(&sem);
}
pthread_exit("quit");
}


 void* handler2(void*argc)
{
while(1)
{
	sem_wait(&sem);
printf("%s\n",buf);
}
pthread_cancel(thread1);
pthread_exit("quit");
}

 int main(int argc, const char *argv[])
 {
	 if(sem_init(&sem,0,0)==-1)
	 {
	 perror("sem_init");
	 return -1;
	 
	 }
if(pthread_create(&thread1,NULL,handler1,NULL)==-1)

{
perror("thread_create");
return -1;

}
if(pthread_create(&thread2,NULL,handler2,NULL)==-1)

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
