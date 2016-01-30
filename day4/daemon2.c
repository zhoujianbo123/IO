#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
 int main(int argc, const char *argv[])
 {
char buf[20]="hello world\n";
   pid_t pid;

   if((pid=fork())==-1)
   {
   perror("fork");
   return -1;
   
   }
if(pid==0)
{

int i,num,res;
setsid();
chdir("/");
umask(0);
num=getdtablesize();
for(i=0;i<num;i++)
{
close(i);
}
	if((res=open("file2",O_RDWR|O_CREAT|O_TRUNC,0666))<0)
{
perror("open");
return -1;

}



while(1)
{
write(res,buf,sizeof(buf));
lseek(res,0,SEEK_SET);
sleep(2);
}



}
if(pid>0)
{
printf("i will exit");
exit(0);

}

 	return 0;
 }
