//fcfs
#incude<stdio.h>
int main(){
	int n,bt[20],wt[20],tat[20],i,j;
	float avg_wt=0,avg_tat=0;
	printf("Enter total no. of processes:");
	scanf("%d",&n);
	printf("Enter Burst Time \n");
	for(i=0;i<n;i++){
		printf("P[%d]:",i+1);
		scanf("%d",&bt[i]);
	}
	
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++){
			wt[i]+=bt[j];
		}
	}
	
	printf("\nProcesses\tBurst Time\t\tWaiting Time\t\tTurn Around Time");
	
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		avg_wt+=wt[i];
		avg_tat+=tat[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
	}
	
	avg_wt/=i;
	avg_tat/=i;
	
	printf("Average Waiting Time:%f",avg_wt);
	printf("Average Turn Around Time:%f",avg_tat);
	return 0;
	
}
