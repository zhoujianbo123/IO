
#include"ipc.h"
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
	system("ipcs -q");
	if((msqid=msgget(key,IPC_CREAT|IPC_EXCL|066))<0)
	{
	
	if((errno==EEXIST))
		msqid=msgget(key,0666);
	else
	{
	perror("msgget");
	exit(1);
	}
	
	
	}
do{
	msgrcv(msqid,&msg,sizeof(msg)-sizeof(long),20,0);
	printf("%s",msg.text);
	msg.type=30;
	strcpy(msg.txt,stdin);
	msgsed(msqid,&msg,sizeof(msg)-sizeof(long),0);

	putchar(10);
}while(strncmp(msg.text,"quit",4)!=0)
 	return 0;
 }
