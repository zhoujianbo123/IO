#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

 int main(int argc, const char *argv[])
 {
 	struct stat type;

	if(stat("day",&type)==-1)
	{
	perror("stat");
	return -1;
	}
	printf("size :%ld",type.st_size);
	if(S_ISREG(type.st_mode))
	{
	printf("this a normal file\n");
	}
	
	}
 	return 0;
 }
