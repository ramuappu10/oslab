#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{	
	pid_t b,c,d,e,f,g,h,i;
	b=fork();
	if(b==0)
	{
		printf("Child B PID: %d\nParent A PID: %d\n\n",getpid(),getppid());
		d=fork();
		if(d==0)
		{
			printf("Child D PID: %d\nParent B PID: %d\n\n",getpid(),getppid());
			h=fork();
			if(h==0)
			{
				printf("Child H PID: %d\nParent D PID: %d\n\n",getpid(),getppid());
				i=fork();
				if(i==0)
				{
					printf("Child I PID: %d\nParent H PID: %d\n\n",getpid(),getppid());
				}
			}
		}
		else if(d>0)
		{
			wait(NULL);
			e=fork();
			if(e==0)
			{
				printf("Child E PID: %d\nParent B PID: %d\n\n",getpid(),getppid());
			}
			else if(e>0)
			{
				wait(NULL);
				f=fork();
				if(f==0)
				{
					printf("Child F PID: %d\nParent B PID: %d\n\n",getpid(),getppid());
				}
			}
		}
	}
	else if(b>0)
	{
	wait(NULL);
		c=fork();
		if(c==0)
		{
			printf("Child C PID: %d\nParent A PID: %d\n\n",getpid(),getppid());
			g=fork();
			if(g==0)
			{
				printf("Child G PID: %d\nParent C PID: %d\n\n",getpid(),getppid());
			}
		}
	}
}
