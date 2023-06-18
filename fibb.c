#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
void main()
{
	int n,a,b,c;
	printf("Enter the limiting value:");
	scanf("%d",&n);
	pid_t fid=fork();
	if(fid==0)
	{
		printf("Printing fibonaci: \n");
		a=0;
		b=1;
		printf("%d ",a);
		printf("%d ",b);
		for(int i=0;i<n-2;i++)
		{
			c=a+b;
			printf("%d ",c);
			a=b;
			b=c;
		}
		printf("\n");
	}
	else if(fid>0)
	{
		printf("printing prime numbers: \n");
		int j=1;
		while(j<=n)
		{
			if(j==2)
				printf("%d ",j);
			else if(j==3)
				printf("%d ",j);
			else if(j==7)
				printf("%d ",j);
			else
			{
				for(int k=2;k<=j/2;k++)
				{
					if(j%k==0)
						break;
					else
						printf("%d ",j);
				} 
			}
			j++;
		}
	}
	printf("\n");
}
