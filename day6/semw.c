#include"ipc.h"
#include<sys/sem.h>
#include<stdio.h>

#define READ 0
#define WRITE 1

#define SIZE 1024
#define N    1024

 union semun{
 int val ;
 struct semid_ds *buf;
 unsigned short *array;
 };


 int main(int argc, const char *argv[])
 {
 	int semid;
	key_t key;
	union semun mysemun;
	struct sembuf mysembuf[2];
	key=ftok(".",1);

	if((semid=semget(key,2,IPC_CREAT|IPC_EXCL|0666))<0)
	{
	if(errno=EEXIST)
	{
	semid=semget(key,2,0666);
	}
	else
	{
	perror("fail to semget create");
	return -1;
		
	
	}
	
	}

system("ipcs -s");
#if 1
	mysemun.val=5;
semctl(semid,0,SETVAL,mysemun);
mysemun.val=2;
semctl(semid,1,SETVAL,mysemun);
#endif
mysembuf[0].sem_num=0;
mysembuf[0].sem_op=-1;
mysembuf[0].sem_flg=0;

mysembuf[1].sem_num=1;
mysembuf[1].sem_op=-1;
mysembuf[1].sem_flg=0;

semop(semid,mysembuf,2);

printf("0= %d\n",semctl(semid,0,GETVAL));
printf("1= %d\n",semctl(semid,1,GETVAL));

system("ipcs -s");
semctl(semid,0,IPC_RMID);
system("ipcs -s");

 	return 0;
 }

