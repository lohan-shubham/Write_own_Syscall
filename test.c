#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	int pid;
	char* filename=(char*)malloc(sizeof(char)*1024);
	printf("Enter PID - ");
	scanf("%d",&pid);
	printf("Enter File Name- ");
	scanf("%s",filename);

	int flag=syscall(440,pid,filename);
	if(flag==0)
		printf("Success");
	else
		printf("Failure");

	free(filename);
	return 0;
}