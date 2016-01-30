#include<stdio.h>
 int main(int argc, const char *argv[])
 {
 	FILE *fp;
if((fp=fopen("day","w+"))==NULL)
{

printf("error open");
return -1;
}

int a[4];
int n,i;
for(i=1;i<5;i++)
{

a[i-1]=i;

}
n=fwrite(a,sizeof(int),4,fp);

printf("%d",n);


 	return 0;
 }
