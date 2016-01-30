#include<stdio.h>
#include<signal.h>
 int main(int argc, const char *argv[])
 {
 	kill(5913,SIGKILL);
 	return 0;
 }
