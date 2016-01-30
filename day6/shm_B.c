#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<stdlib.h>

#define SIZE 1024 
#define N   128

 int main(int argc, const char *argv[])
 {
 	key_t key;
	int shmid;
	char *shaddr;
	char buf[N]={0};

	if((key=ftok(".",1))<0)
	{
	perror("fail to ftok");
	exit(1);
	}
	if((shmid=shmget(key,SIZE,IPC_CREAT|0666))<0)
	{
	
	perror("shmget");
	exit(1);
	}
	if((shaddr=(char*)shmat(shmid,NULL,0))==(char*)-1)
	{
	perror("fail to shmat");
	exit(1);
	
	}	
	do{
		sleep(3);
printf("shaddr: %s",shaddr);	
	}while(strncmp(buf,"quit",4)!=0);
#if 0
	if(shmdt(shaddr)<0)
	{
	perror("fail to shmat");
	exit(1);
	}
	if(shmctl(shmid,IPC_RMID,NULL)<0)
	{
	perror("fail to shmctl");
	exit(1);
	
	}
#endif
	return 0;
 }
