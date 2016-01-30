#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define  READ  0
#define  WRITE 1

#define  SIZE  1024
#define  N     1024

union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO
								(Linux-specific) */
};

int main(int argc, const char *argv[])
{
	key_t key;
	union semun mysemun;
	int semid;
	int shmid;
	char buf[1024];
	struct sembuf buf2;
	char * shmaddr;

	if((key = ftok(".", 's')) < 0)
	{
		perror("fail to ftok");
		exit(1);
	}
	if((semid = semget(key, 2, IPC_CREAT|0664)) < 0)
	{
		perror("fail to semget");
		exit(1);
	}
	if((shmid = shmget(key, SIZE, IPC_CREAT|0664)) < 0)
	{
		perror("fail to shmget");
		exit(1);
	}
	if((shmaddr = (char*)shmat(shmid, NULL, 0)) ==(char*)-1 )
	{
		perror("fail to shmaddr");
		exit(1);
	}

	mysemun.val=1;
	semctl(semid,WRITE,SETVAL,mysemun);
	mysemun.val=0;
	semctl(semid,READ,SETVAL,mysemun);
	while(1)
	{
	buf2.sem_num=WRITE;
	buf2.sem_op=-1;
	buf2.sem_flg=0;
	semop(semid,&buf2,1);
		printf("Input >");
		fgets(buf, N, stdin);
		strcpy(shmaddr, buf);

		if(strncmp(buf, "quit", 4) == 0)
		{
			break;
		}
    buf2.sem_num=READ;
	buf2.sem_op=1;
	buf2.sem_flg=0;
	semop(semid,&buf2,1);

	}
	
	if(semctl(semid, READ, IPC_RMID) < 0)
	{
		perror("fail to semctl");
		exit(1);
	}
	if(shmdt(shmaddr) < 0)
	{
		perror("fail to shmdt");
		exit(1);
	}
	if(shmctl(shmid, IPC_RMID, NULL) < 0)
	{
		perror("fail to shmctl");
		exit(1);
	}


	
	return 0;
}
