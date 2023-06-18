#include <stdio.h>
void main()
{
	int n,i,totalwt=0,totaltat=0,prev;
	float totalbt=0;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int at[n],bt[n],burst[n],compt[n],tat[n],wt[n],time=0,count=0,smallest=0;
	for (i=0;i<n;i++)
	{
		printf("\nEnter the arrival time of process %d:",i);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time of process %d:",i);
		scanf("%d",&bt[i]);
		burst[i]=bt[i];
	}
	time=at[0];
	while (count!=n)
	{
		for(i=0;i<n;i++)
		{
			if (bt[i]!=0)
			{
				smallest=i;
				break;
			}
		}
		for (i=0;i<n;i++)
		{
			if (at[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
			{
				smallest=i;
			}
		}
		bt[smallest]--;
		time++;
		if (bt[smallest]==0)
		{
			count++;
			compt[smallest]=time;
			tat[smallest]=compt[smallest]-at[smallest];
			wt[smallest]=tat[smallest]-burst[smallest];
		}
	}
	printf("\nPROCESS ID\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURNAROUND TIME\t WAITING TIME\n");
	for (i=0;i<n;i++)
	{
		totalwt+=wt[i];
		totaltat+=tat[i];
		totalbt+=burst[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,at[i],burst[i],compt[i],tat[i],wt[i]);
	}
	printf("\nAverage waiting time:%d\n",(totalwt/n));
	printf("Average turnaround time:%d\n",(totaltat/n));
	printf("Throughput:%f\n",((float)n)/totalbt);
}
	
