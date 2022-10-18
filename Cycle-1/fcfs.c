/*

Ex.No:5.c
CPU SCHEDULING ALGORITHMS
FCFS
AIM:
 To write a C program for implementation of FCFS and SJF scheduling algorithms.
ALGORITHM:
Step 1: Inside the structure declare the variables.
Step 2: Declare the variable i,j as integer,totwtime and totttime is equal to zero.
Step 3: Get the value of „n‟ assign pid as I and get the value of p[i].btime.
Step 4: Assign p[0] wtime as zero and tot time as btime and inside the loop calculate wait time
and turnaround time.
Step 5: Calculate total wait time and total turnaround time by dividing by total number of
process.
Step 6: Print total wait time and total turnaround time.
Step 7: Stop the program.

*/

#include<stdio.h>

int main(){
	int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j; 
	printf("Enter Total Number of processes (max 20) : ");
	scanf("%d",&n);

	printf("\n Enter Process Burst Time \n"); 
	for( i = 0; i < n; i++){ 
		printf("P[%d] : ",i+1);
		scanf("%d" , &bt[i]);
	}
	wt[0] = 0;
	for( i = 1; i < n ; i++){ 
		wt[i] = 0;
		for ( j = 0; j < i; j++)
			wt[i] += bt[j];
		}
	printf("\n Process \tBurst Time\tWaiting Time\tTurnaround Time");

	for( i = 0; i < n; i++){
		tat[i] = bt[i] + wt[i];
		avwt += wt[i];
		avtat += tat[i];
		printf("\n P[%d] \t\t\t %d \t %d \t\t %d",i+1,bt[i],wt[i],tat[i]);
	}
	avwt /= i;
	avtat /= i;
printf("\n\n Average Waiting Time:%d",avwt); printf("\n Average Turnaround Time:%d \n",avtat);

return 0;
}
