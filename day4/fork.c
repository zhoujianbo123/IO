#include<stdio.h>
 int main(int argc, const char *argv[])
 {
  int pid;
  int a=10;

  pid=fork();
  if(pid==-1)
	{
	perror("fork");
	return -1;
	}
  if(pid==0)
  {
  printf("this is a child\n");
  printf("child --%d\n",getpid());
  printf("parent --%d\n",getppid());

  }
  if(pid>0)
  {
	  sleep(1);
 printf("this is a parent\n");
 printf("child --%d\n",pid);
 printf("parent --%d\n",getpid());
  }
 	return 0;
 }
