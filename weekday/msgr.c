#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
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
	send.type=200;
	rcv.type=100;
	while(1)
	{
		sleep(2);

		if (msgrcv(msgid,&rcv,SIZE,100,0)<0)
		{
			printf("failed to msgrcv");
			exit(1);
		
		}
		if(strncmp(rcv.data,"quit",4)==0)
		{
			break;
		}
printf("B receive : %s\n",rcv.data);
		fgets(send.data,N,stdin);
		if(strncmp(send.data,"quit",4)==0)
		{
			break;
		}
		msgsnd(msgid,&send,SIZE,0);
	}
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}

