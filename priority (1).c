#include <stdio.h>
void main()
{
	int n,i,j=0,opt,totalwt=0,totaltat=0,prev;
	float totalbt=0;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int at[n],prio[n],bt[n],compt[n],burst[n],tat[n],wt[n],pid[n],time=0,count=0,high;
	for (i=0;i<n;i++)
	{
		printf("\nEnter the arrival time of process %d:",i);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time of process %d:",i);
		scanf("%d",&bt[i]);
		printf("\nEnter the priority of process %d:",i);
		scanf("%d",&prio[i]);
		pid[i]=i;
		burst[i]=bt[i];
	}
	printf("Enter scheduling algorithm:\n1->Non-preemptive scheduling\n2->Preemptive scheduling\nEnter option:");
	scanf("%d",&opt);
	if (opt==1)
	{
		printf("\nGANTT CHART\nID\tTIME\n");
		printf("P%d\t%d --------start\n",0,0);
		prev=0;
		while(count!=n)
		{
			for(i=0;i<n;i++)
			{
				if(bt[i]!=0)
				{
					high=i;
					break;
				}
			}
			for (i=0;i<n;i++)
			{
				if (at[i]<=time && prio[i]<prio[high] && bt[i]>0)
				{
					high=i;
				}
			}
			if(prev!=high)
			{
				printf("P%d\t%d\n",high,time);
			}
			while (bt[high]!=0)
			{
				bt[high]--;
				time++;
			}
			prev=high;
			count++;
			compt[high]=time;
			tat[high]=compt[high]-at[high];
			wt[high]=tat[high]-burst[high];
		}
		printf("P%d\t%d--------end\n",high,time);
		printf("\nPROCESS ID\tPRIORITY\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURNAROUND TIME\t WAITING TIME\n");
		for (i=0;i<n;i++)
		{
			totalwt+=wt[i];
			totaltat+=tat[i];
			totalbt+=burst[i];
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,prio[i],at[i],burst[i],compt[i],tat[i],wt[i]);
		}
		printf("\nAverage waiting time:%d\n",(totalwt/n));
		printf("Average turnaround time:%d\n",(totaltat/n));
		printf("Throughput:%f\n",((float)n)/totalbt);
	}
	else if (opt==2)
	{
		printf("\nGANTT CHART\nID\tTIME\n");
		printf("P%d\t%d --------start\n",0,0);
		prev=0;
		while(count!=n)
		{
			for(i=0;i<n;i++)
			{
				if(bt[i]!=0)
				{
					high=i;
					break;
				}
			}
			for (i=0;i<n;i++)
			{
				if (at[i]<=time && prio[i]<prio[high] && bt[i]>0)
				{
					high=i;
				}
			}
			if(prev!=high)
			{
				printf("P%d\t%d\n",high,time);
			}
			bt[high]--;
			time++;
			prev=high;
			if (bt[high]==0)
			{
				count++;
				compt[high]=time;
				tat[high]=compt[high]-at[high];
				wt[high]=tat[high]-burst[high];
			}
		}
		printf("P%d\t%d --------end\n",high,time);
		printf("\nPROCESS ID\tPRIORITY\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURNAROUND TIME\t WAITING TIME\n");
		for (i=0;i<n;i++)
		{
			totalwt+=wt[i];
			totaltat+=tat[i];
			totalbt+=burst[i];
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,prio[i],at[i],burst[i],compt[i],tat[i],wt[i]);
		}
		printf("\nAverage waiting time:%d\n",(totalwt/n));
		printf("Average turnaround time:%d\n",(totaltat/n));
		printf("Throughput:%f\n",((float)n)/totalbt);
	}
}
