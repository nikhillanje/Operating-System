/*
Name: Nikhil Lanje
Class: SY-(A)
Roll No: 113
Batch: S1
*/
// Non-Preemptive Scheduling //
#include <stdio.h>
#include <string.h>

void main() {
    int n, i, j;
    char pname[10][10], temp[10], executed_order[10][10];
    int at[10], bt[10], wt[10], tt[10], completed[10] = {0};
    int current_time = 0, total_completed = 0;
    int sumwt = 0, sumtt = 0;
    float avgwt, avgtt;

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

    // Sort processes by arrival time (optional but helps in visualization)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                // Swap arrival time
                int t = at[i];
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

    // SJF Scheduling
    while(total_completed < n) {
        int idx = -1, min_bt = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && completed[i] == 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            current_time++; // Idle time
        } else {
            wt[idx] = current_time - at[idx];
            if(wt[idx] < 0) wt[idx] = 0;

            tt[idx] = wt[idx] + bt[idx];
            current_time += bt[idx];

            completed[idx] = 1;
            sumwt += wt[idx];
            sumtt += tt[idx];

            strcpy(executed_order[total_completed], pname[idx]);
            total_completed++;
        }
    }

    avgwt = (float)sumwt / n;
    avgtt = (float)sumtt / n;

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround");
    for(i = 0; i < n; i++) {
        printf("\n%s\t%d\t%d\t%d\t%d", pname[i], at[i], bt[i], wt[i], tt[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtt);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    printf(" ");
    for(i = 0; i < n; i++) {
        printf("| %s ", executed_order[i]);
    }
    printf("|\n");

    printf("0 ");
    current_time = 0;
    for(i = 0; i < n; i++) {
        // Find burst time of executed process
        for(j = 0; j < n; j++) {
            if(strcmp(executed_order[i], pname[j]) == 0) {
                current_time += bt[j];
                printf("%d ", current_time);
                break;
            }
        }
    }
    printf("\n");
}
/*
Enter the number of processes: 5

Enter details for process 1:
Process name: p1
Arrival time: 2
Burst time: 1

Enter details for process 2:
Process name: p2
Arrival time: 1
Burst time: 5

Enter details for process 3:
Process name: p3
Arrival time: 4
Burst time: 1

Enter details for process 4:
Process name: p4
Arrival time: 0
Burst time: 6

Enter details for process 5:
Process name: p5
Arrival time: 2
Burst time: 3

Process Arrival Burst   Waiting Turnaround
p4      0       6       0       6
p2      1       5       10      15
p1      2       1       4       5
p5      2       3       6       9
p3      4       1       3       4

Average Waiting Time: 4.60
Average Turnaround Time: 7.80

Gantt Chart:
 | p4 | p1 | p3 | p5 | p2 |
0 6 7 8 11 16

*/