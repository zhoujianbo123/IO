#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stddef.h>
#include<errno.h>

int main(int argc, const char *argv[])
{
	DIR *dp;
	struct dirent *ep;
	struct stat st;
	char dirp[50];

	printf("please input a dir name :/n")
		scanf("%s",&dirp);
	dp=opendir(dirp);
	printf("filename :\ttype:\tpermission\taccesstime\tlastmodtime\tsize\t");

	if(dp!=NULL)
	{
		while(ep=readdir(dp))
		{

			if(ep->d_name[0]!='.')
			{
				if(stat(ep->d_name,&st)!=-1)
				{
					printf("%s\t",ep->d_name);
					if((st.st_mode&S_IFMT)==S_IFDIR)
						printf("directory\t");
					else if((st.st_mode&S_IFMT)==S_IFBLK)
						printf("block special file \t");
					else if((st.st_mode&S_IFMT)==S_IFCHR)
						printf("character special file\t");


					else if((st.st_mode&S_IFMT)==S_IFREG)
						printf("ordinary file\t");
					else if((st.st_mode&S_IFMT)==S_IFIFO)
						printf("pipefile file\t");
					printf("%o\t",st.st_mode&0x1ff); 
					printf("%15s\t",ctime(st.st_atime));
					printf("%15s\t",ctime(st.st_mtime));
					printf("%ld\n",st.st_size);

				}
			}

		}
		closedir(dp);
	}
	else 
		puts("couln't open the directory \n");
	return 0;
}

