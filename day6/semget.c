#include"ipc.h"
#include<sys/sem.h>

 int main(int argc, const char *argv[])
 {
 	int semid;
	key_t key;
	key =ftok(".",1);

	system("ipcs -s");
	if((semid=semget(key,2,IPC_CREAT|IPC_EXCL|0666))==-1)
	{
	if(errno=EEXIST	)
	{
	semid=semget(key,2,0666);
	}
	else
	{
	perror("semget");
	return -1;
	}
	}
	system("ipcs -s");
 	return 0;
 }
