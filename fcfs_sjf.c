#include <stdio.h>
void main()
{
	int n,i,j,opt,totalwt=0,totaltat=0;
	float totalbt=0;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int bt[n],compt[n],tat[n],wt[n],pid[n],temp;
	for (i=0;i<n;i++)
	{
		printf("\nEnter the burst time of process %d:",i);
		scanf("%d",&bt[i]);
		pid[i]=i;
	}
	printf("Enter scheduling algorithm:\n1-FCFS scheduling\n2-SJF scheduling\nEnter option:");
	scanf("%d",&opt);
	if (opt==1)
	{
		/*----------FIRST COME FIRST SERVE------------*/
		wt[0]=0;
		tat[0]=bt[0];
		compt[0]=bt[0];
		for (i=1;i<n;i++)
		{
			compt[i]=compt[i-1]+bt[i];
			tat[i]=compt[i]-i;
			wt[i]=tat[i]-bt[i];
		}
		printf("\nPROCESS ID\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURNAROUND TIME\t WAITING TIME\n");
		for (i=0;i<n;i++)
		{
			totalwt+=wt[i];
			totaltat+=tat[i];
			totalbt+=bt[i];
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,i,bt[i],compt[i],tat[i],wt[i]);
		}
		printf("\nAverage waiting time:%d\n",(totalwt/n));
		printf("Average turnaround time:%d\n",(totaltat/n));
		printf("Throughput:%f\n",((float)n)/totalbt);
	}
	else if (opt==2)
	{
		/*----------SHORTEST JOB FIRST----------*/
		for (i=0;i<n;i++)
		{
			for (j=0;j<n-i-1;j++)
			{
				if (bt[j]>bt[j+1])
				{
					temp=bt[j];
					bt[j]=bt[j+1];
					bt[j+1]=temp;
					temp=pid[j];
					pid[j]=pid[j+1];
					pid[j+1]=temp;
				}
			}
		}
		wt[pid[0]]=0;
		tat[pid[0]]=bt[0];
		compt[pid[0]]=bt[0];
		for (i=1;i<n;i++)
		{
			compt[pid[i]]=compt[pid[i-1]]+bt[i];
			tat[pid[i]]=compt[pid[i]]-0;
			wt[pid[i]]=tat[pid[i]]-bt[i];
		}
		printf("\nPROCESS ID\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURNAROUND TIME\t WAITING TIME\n");
		for (i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if (pid[j]==i)
				{
					totalwt+=wt[i];
					totaltat+=tat[i];
					totalbt+=bt[i];
					printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t %d\n",pid[j],0,bt[j],compt[pid[j]],tat[pid[j]],wt[pid[j]]);
					break;
				}
			}
		}
		printf("\nAverage waiting time:%d\n",(totalwt/n));
		printf("Average turnaround time:%d\n",(totaltat/n));
		printf("Throughput:%f\n",n/totalbt);
	}	
}
