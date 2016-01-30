#include<stdio.h>
#include<unistd.h>
#include<signal.h>

 	void handler(int sig)
{
	if(sig==SIGINT)
	{
	puts("haha ctrl+c");
	}
	if(sig==SIGQUIT)
	{
	puts("ctrl + \\");
	}
}
 int main(int argc, const char *argv[])
 {
	 while(1)
	 {
  signal(SIGINT,handler);
  signal(SIGQUIT,handler);
	 }
 	return 0;
 }
