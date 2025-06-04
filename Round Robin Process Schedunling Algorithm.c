/*
Name: Nikhil Lanje
Class: SY-(A)
Roll No: 113
Batch: S1
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char pname[10][10];
    int at[10], bt[10], rt[10], wt[10] = {0}, tt[10] = {0};
    int quantum, time = 0, remain, flag = 0;
    int sumwt = 0, sumtt = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    remain = n;

    for(i = 0; i < n; i++) {
        printf("\nEnter details for process %d:\n", i + 1);
        printf("Process name: ");
        scanf("%s", pname[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    int queue[100], front = 0, rear = 0;
    int visited[10] = {0};
    int completed[10] = {0};
    int start_time[100], end_time[100];
    char exec_order[100][10];
    int exec_index = 0;

    for(i = 0; i < n; i++) {
        if(at[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while(remain > 0) {
        if(front == rear) {
            // CPU is idle
            time++;
            for(i = 0; i < n; i++) {
                if(at[i] <= time && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        start_time[exec_index] = time;

        if(rt[idx] <= quantum) {
            time += rt[idx];
            rt[idx] = 0;
            completed[idx] = 1;
            remain--;

            end_time[exec_index] = time;
            strcpy(exec_order[exec_index++], pname[idx]);

            tt[idx] = time - at[idx];
            wt[idx] = tt[idx] - bt[idx];

            sumwt += wt[idx];
            sumtt += tt[idx];
        } else {
            time += quantum;
            rt[idx] -= quantum;

            end_time[exec_index] = time;
            strcpy(exec_order[exec_index++], pname[idx]);
        }


        for(i = 0; i < n; i++) {
            if(at[i] <= time && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if(rt[idx] > 0)
            queue[rear++] = idx;
    }

    float avgwt = (float)sumwt / n;
    float avgtt = (float)sumtt / n;

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", pname[i], at[i], bt[i], wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtt);

    // Gantt Chart
    printf("\nGantt Chart:\n ");
    for(i = 0; i < exec_index; i++) {
        printf("| %s ", exec_order[i]);
    }
    printf("|\n");

    printf("0 ");
    for(i = 0; i < exec_index; i++) {
        printf("%d ", end_time[i]);
    }
    printf("\n");

    return 0;
}
/*
Enter the number of processes: 5

Enter details for process 1:
Process name: p1
Arrival time: 0
Burst time: 8

Enter details for process 2:
Process name: p2
Arrival time: 5
Burst time: 2

Enter details for process 3:
Process name: p3
Arrival time: 1
Burst time: 7

Enter details for process 4:
Process name: p4
Arrival time: 6
Burst time: 3

Enter details for process 5:
Process name: p5
Arrival time: 8
Burst time: 5

Enter the time quantum: 3

Process	Arrival	Burst	Waiting	Turnaround
p1	0	8	14	22
p2	5	2	4	6
p3	1	7	15	22
p4	6	3	5	8
p5	8	5	12	17

Average Waiting Time: 10.00
Average Turnaround Time: 15.00

Gantt Chart:
 | p1 | p3 | p1 | p2 | p4 | p3 | p5 | p1 | p3 | p5 |
0 3 6 9 11 14 17 20 22 23 25 


=== Code Execution Successful ===
*/