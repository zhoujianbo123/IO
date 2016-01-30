#include<stdio.h>
#include<sys/sem.h>
#include"pic.h"

#define N 1024
#define SIZE 1024

union semun{
int val;
};


int init_sem(int semid,int array[],int n)
{
union semun myun;
int i=0;
for(i=0;i<n;i++)
{

myun.val=array[i];
if(semctl(semid,i,SETVAL,myun)<0)
{
perror("fail to semctl");
exit(1);
}

}

return 0;

}

int sem_p(int semid ,int num)
{
struct sembuf buf;
buf.sem_num=num;
buf.sem_op =-1;
buf.sem_flg=0;
if(semop(semid,&buf,1)<0)
{
perror("fail to semop");
exit(-1);

}
return 0;
}

int sem_v(int semid,int num)
{
struct sembuf buf;
buf.sem_num=num;
buf.sem_op=1;
buf.sem_flg=0;
if(semop(semid,&buf,1)<0)
{
perror("fail to sem_op");
exit(1);

}
return 0;
}
 
 int main(int argc, const char *argv[])
 {
 	key_t key;
	int semid;
	int shmid;
	char buf[N]={0};
	int arrary[2]={0,1};
	char *shamddr;

	if((key=ftok(".","1"))<0)
	{
	perror("fail to ftok");
	exit(-1);
	
	}
	if(semid=semget(key,2,IPC_CREAT|EXCL|0666)<0)
	{
	if(errno==EEXIST)
	{
	sempid=semget(key,2,0666);

	}
	else
	{
	perror("fail to semget");
	exit(-1);
	}
	}

	if((shmid=shmget(key,SIZE,IPC_CREAT|0666))<0)
	{
	
	perror("fail to shmget");
	exit(-1);
	}

 	return 0;
 }
