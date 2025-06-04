#include<stdio.h>
#include<string.h>
void main()
{
 float avgwt,avgtt;
 char pname[10][10],c[10][10];
 int wt[10],tt[10],bt[10],pt[10],t,q,i,n,sum=0,sbt=0,ttime,j,ss=10;

printf("\n\n Enter the number of processes : ");
scanf("%d",&n);

printf("\n\n Enter the NAME and BURSTTIME ");
for(i=0;i<n;i++)
{
    printf("\n\n NAME : ");
    scanf("%s",&pname[i]);
    printf("\n\n BURSTTIME : ");
    scanf("%d",&bt[i]);
}

printf("\n\n Enter the priorities of the processes "); 
for(i=0;i<n;i++) 
{
    printf("\n\n Priority of process%d : ",i+1);
    scanf("%d",&pt[i]);
}

for(i=0;i<n;i++) 
for(j=i+1;j<n;j++) 
{ 
    if(pt[i]>pt[j])
    {
        t=pt[i];
        pt[i]=pt[j];
        pt[j]=t;
        q=bt[i];
        bt[i]=bt[j];
        bt[j]=q;
        strcpy(c[i],pname[i]);
        strcpy(pname[i],pname[j]);
        strcpy(pname[j],c[i]);
    } 
}
wt[0]=0; 

for(i=0;i<n;i++) 
{
    wt[i+1]=wt[i]+bt[i];
    sum=sum+wt[i];
    sbt=sbt+wt[i+1];
    tt[i]=wt[i]+bt[i];
    ss=ss+bt[i];
 
}


printf("\n\n GANTT CHART"); 
printf("\n-----------------------------------------------------------------\n");
for(i=0;i<n;i++)
printf("|\t%s\t",pname[i]);
printf("\n-----------------------------------------------------------------\n");
for(i=0;i<n;i++)
printf("%d\t\t",wt[i]);
printf("%d\n",ss);
printf("\n\n Total WAITING TIME of the process = %d",sum);
printf("\n\n Total TURNAROUND TIME of the process = %d",sbt);
avgwt=(float)sum/n;
avgtt=(float)sbt/n;
printf("\n\n Average WAITING TIME of the process = %f",avgwt);
printf("\n\n Average TURNAROUND TIME of the process = %f",avgtt);
}

/*
PS C:\Users\nikhi\OneDrive\Desktop\New folder> cd "c:\Users\nikhi\OneDrive\Desktop\New folder\"
 Enter the number of processes : 4
 Enter the NAME and BURSTTIME 
 NAME : p1
 BURSTTIME : 8
 NAME : p2
 BURSTTIME : 3
 NAME : p3
 BURSTTIME : 6
 NAME : p4
 BURSTTIME : 1
 Enter the priorities of the processes
 Priority of process1 : 1
 Priority of process2 : 5
 Priority of process3 : 2
 Priority of process4 : 4
 GANTT CHART
-----------------------------------------------------------------
|       p1      |       p3      |       p4      |       p2
-----------------------------------------------------------------
0               8               14              15              28
 Total WAITING TIME of the process = 37
 Total TURNAROUND TIME of the process = 55

 Average WAITING TIME of the process = 9.250000

 Average TURNAROUND TIME of the process = 13.750000
PS C:\Users\nikhi\OneDrive\Desktop\New folder> 
*/
