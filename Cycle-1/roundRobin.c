/*

Ex.No:5.b
CPU SCHEDULING ALGORITHMS
ROUND ROBIN SCHEDULING
AIM:
 To write a C program for implementation of Round Robin scheduling algorithms.
ALGORITHM:
Step 1: Inside the structure declare the variables.
Step 2: Declare the variable i,j as integer, totwtime and totttime is equal to zero.
Step 3: Get the value of „n‟ assign p and allocate the memory.
Step 4: Inside the for loop get the value of burst time and priority and read the time quantum.
Step 5: Assign wtime as zero.
Step 6: Check p[i].pri is greater than p[j].pri .
Step 7: Calculate the total of burst time and waiting time and assign as turnaround time.
Step 8: Stop the program.

*/

#include <stdio.h>
int main(){ 
        int count, j, n, time, remain, flag = 0, time_quantum;
        int wait_time = 0,turnaround_time = 0, at[10], bt[10], rt[10];
        printf("Enter Total Process : \t ");
        scanf("%d",&n);
        remain = n;
        for( count = 0; count < n; count++){
                printf("Enter Arrival Time and Burst Time for Process Process Number %d :", count+1);
                scanf("%d",&at[count]); 
                scanf("%d",&bt[count]);
                rt[count] = bt[count];
        }
        printf("Enter Time Quantum : \t");
        scanf("%d",&time_quantum);
        printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
        for( time = 0,count=0; remain != 0;){
                if(rt[count] <= time_quantum && rt[count] > 0 ){
                        time += rt[count];
                        rt[count] = 0;
                        flag = 1;
                } 
                else if( rt[count] > 0){
                        rt[count] -= time_quantum;
                        time += time_quantum;
                        }
                if( rt[count] == 0 && flag == 1){ 
                        remain--;
                        printf("P[%d]\t|\t%d\t\t\t|\t\t%d\n",count+1, time-at[count], time-at[count]-bt[count]);
                        wait_time += time - at[count] - bt[count];
                        turnaround_time += time - at[count];
                        flag=0;
                        }
                if(count == n-1)
                        count=0;

                else if( at[count+1] <= time)
                        count++;
                else
                        count=0;
                }
                printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n); 
                printf("\nAvg Turnaround Time =%f\n", turnaround_time * 1.0 / n);

return 0;
}
