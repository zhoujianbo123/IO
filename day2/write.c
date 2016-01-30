#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

 int main(int argc, const char *argv[])
 {

int fd;
char buf[128]="miss you so much";
char star[128];
int n,m,p;

if((fd=open("file",O_RDWR |O_TRUNC))==-1)
{
printf("error open");
return -1;
}


n=write(fd,buf,sizeof(buf));
p=lseek(fd,0,SEEK_SET);
m=read(fd,star,n);

printf("n=%d\n",n);
printf("m=%d\n",m);
printf("p=%d\n",p);
printf("%s\n",star);
 	return 0;
 }
