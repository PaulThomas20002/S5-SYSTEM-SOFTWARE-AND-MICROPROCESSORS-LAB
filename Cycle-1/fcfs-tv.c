#include <stdio.h>
struct process
{ int pid;
  float at,bt,ct,tat,wt,st;
} p[100],temp;

void fcfs(struct process a[100],int n)
{
    int i,j;
    float  avgtat = 0,avgwt = 0,time = 0,z=0;
    char s[]="        ";
    
    for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
            if (a[j].at>a[j+1].at)
            {
                temp=a[j];
                a[j]=a[j + 1];
                a[j+1]=temp;
            }
      
    printf("\nGantt Chart\n");
    for (i=0;i<n;)
    {
        if (a[i].at<=time)
        {   if(z!=0)
            {
             printf("%f - %f -> NULL\n",time-z,time);
             z=0;
            }
            a[i].st=time;
            time+=a[i].bt;
            a[i].ct=time;
            a[i].tat=time-a[i].at;
            a[i].wt=a[i].tat-a[i].bt;
            avgtat+=a[i].tat;
            avgwt+=a[i].wt;    
            printf("%f - %f -> P%d\n",a[i].st,a[i].ct,a[i].pid);
            i++;
        }
        else
        {
            z++;
            ++time;
        }
    }

    avgtat/=n;
    avgwt/=n;
    
        for (i=0;i<n-1;i++)
         for (j=0;j<n-i-1;j++)
            if (a[j].pid>a[j+1].pid)
            {
                temp=a[j];
                a[j]=a[j + 1];
                a[j+1]=temp;
            }
            
    printf("\nProcess Id      AT%s  BT%s CT%s  TAT%s WT\n",s,s,s,s);   
    for(i=0;i<n;i++)
    {
        printf("%6d       %f    %f   %f    %f    %f\n",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
    }

    printf("\nAvg TAT : %f", avgtat);
    printf("\nAvg WT  : %f\n", avgwt);
}
     
int main()
{
    int n,i;
    printf("Enter the no. of Proceses : ");
    scanf("%d",&n);
    printf("\nEnter the Arrival Time and Burst Time : \n");
    for (i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("\nProcess %d\n", p[i].pid);
        printf("Arrival Time : ");
        scanf("%f",&p[i].at);
        printf("Burst Time : ");
        scanf("%f",&p[i].bt);
    }

    fcfs(p,n);
    return 0;
}



