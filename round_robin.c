#include <stdio.h>

void findAvgTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], remTime[n], time = 0, total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) remTime[i] = bt[i];

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remTime[i] > 0) {
                done = 0;
                if (remTime[i] > quantum) {
                    time += quantum;
                    remTime[i] -= quantum;
                } else {
                    time += remTime[i];
                    wt[i] = time - bt[i];
                    remTime[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("Avg Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Avg Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {24, 3, 5, 7};
    int quantum = 4;
    int n = sizeof(processes) / sizeof(processes[0]);

    printf("P\tBT\tWT\tTAT\n");
    findAvgTime(processes, n, burst_time, quantum);
    return 0;
}