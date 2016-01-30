#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<stdlib.h>
#define N 256
struct mymsg{
	long type;
	char data[N];
};
#define  SIZE (sizeof(struct mymsg)-sizeof(long))
int main(int argc, const char *argv[])
{
	key_t key;
	int msgid;
	struct mymsg send;
	struct mymsg rcv;
	if((key=ftok("./",'5'))<0)
	{
		perror("fail to ftok");
		exit(1);
	}
	if(msgid=msgget(key,IPC_CREAT|0666)==-1)
	{

		perror("msgget failed");
		exit(1);
	}
	send.type=100;
	rcv.type=200;
	while(1)
	{

		fgets(send.data,N,stdin);
		if(strncmp(send.data,"quit",4)==0)
		{
			break;
		}
		msgsnd(msgid,&send,SIZE,0);
		if (msgrcv(msgid,&rcv,SIZE,200)<0)
		{
			printf("failed to msgrcv");
			exit(1);

		}
		printf("A receive :%s\n",rcv.data);
	}	
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}

