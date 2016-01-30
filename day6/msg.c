#include"ipc.h"
#include<string.h>
#define N 64
struct msgbuf{
long mytype;
char text[N];
};
 int main(int argc, const char *argv[])
 {
	 struct msgbuf msg;

 	int msqid;
	key_t key;
	key=ftok(".",1);
	if((msqid=msgget(key,IPC_CREAT|IPC_EXCL|066))==-1)
	{
	
	if(errno==EEXIST)
		msqid=msgget(key,0666);
	else
	{
	perror("msgget");
	exit(1);
	}
	
	}

	msg.mytype=20;
	msgsnd(msqid,&msg,sizeof(msg)-sizeof(long),0);
	
	}
	system("ipcs -q");
 	return 0;
 }
