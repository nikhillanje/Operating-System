/*
Name: Nikhil Lanje
class :  SY-(A)
Roll no :- 113
Batch :- S1
*/
#include <stdio.h>
#include <string.h>

void main() {
    float avgwt, avgtt;
    char pname[10][10], temp[10];
    int wt[10], tt[10], bt[10], at[10], t, n, sumwt = 0, sumtt = 0, i, j, current_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details for process %d:\n", i + 1);
        printf("Process name: ");
        scanf("%s", pname[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
    }

    // Sorting based on arrival time
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                // Swap arrival time
                t = at[i];
                at[i] = at[j];
                at[j] = t;

                // Swap burst time
                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;

                // Swap process name
                strcpy(temp, pname[i]);
                strcpy(pname[i], pname[j]);
                strcpy(pname[j], temp);
            }
        }
    }

    // Initialize waiting time and turnaround time
    for(i = 0; i < n; i++) {
        if(current_time < at[i]) {
            current_time = at[i];  // CPU remains idle
        }
        wt[i] = current_time - at[i];  // Waiting time calculation
        tt[i] = wt[i] + bt[i];  // Turnaround time calculation
        current_time += bt[i];  // Update current time

        sumwt += wt[i];
        sumtt += tt[i];
    }

    avgtt = (float)sumtt / n; // Average turnaround time
    avgwt = (float)sumwt / n; // Average waiting time

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++) {
        printf("\n%s\t%d\t\t%d\t\t%d\t\t%d", pname[i], at[i], bt[i], wt[i], tt[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f", avgtt);

    // Print Gantt Chart
    printf("\n\nGantt Chart:\n ");
    for(i = 0; i < n; i++) {
        printf("| %s ", pname[i]);
    }
    printf("|\n");

    // Print timeline including CPU idle time
    printf("%d ", at[0]);
    current_time = at[0];
    for(i = 0; i < n; i++) {
        if(current_time < at[i]) {
            printf("--idle-- %d ", at[i]);  // Indicate CPU idle time
            current_time = at[i];
        }
        current_time += bt[i];
        printf("%d ", current_time);
    }
    printf("\n");
}
/*
Exmaple 1 :
Enter the number of processes: 4

Enter details for process 1:
Process name: p1
Arrival time: 0
Burst time: 2

Enter details for process 2:
Process name: p2
Arrival time: 1
Burst time: 2

Enter details for process 3:
Process name: p3
Arrival time: 4
Burst time: 3

Enter details for process 4:
Process name: p4
Arrival time: 6
Burst time: 4

Process Arrival Time    Burst Time      Waiting Time    Turnaround Time
p1      0               2               0               2
p2      1               2               1               3
p3      4               3               0               3
p4      6               4               1               5

Average Waiting Time: 0.50
Average Turnaround Time: 3.25

Gantt Chart:
 | p1 | p2 | p3 | p4 |
0 2 4 7 11

Exmaple 2 :
Enter the number of processes: 4 

Enter details for process 1:
Process name: p1
Arrival time: 0
Burst time: 2

Enter details for process 2:
Process name: p2
Arrival time: 1
Burst time: 2

Enter details for process 3:
Process name: p3
Arrival time: 5
Burst time: 3

Enter details for process 4:
Process name: p4
Arrival time: 6
Burst time: 4

Process Arrival Time    Burst Time      Waiting Time    Turnaround Time
p1      0               2               0               2
p2      1               2               1               3
p3      5               3               0               3
p4      6               4               2               6

Average Waiting Time: 0.75
Average Turnaround Time: 3.50

Gantt Chart:
 | p1 | p2 | p3 | p4 |
0 2 4 --idle-- 5 8 12
*/