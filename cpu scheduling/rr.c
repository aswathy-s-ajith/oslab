#include <stdio.h>

struct Process {
    int id;
    int burst_time;
};

void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_time[n], wt[n], tat[n], completion_time[n];

    // Step 1: Initialize arrays
    for (int i = 0; i < n; ++i) {
        remaining_time[i] = processes[i].burst_time;
        wt[i] = tat[i] = completion_time[i] = 0;
    }

    int current_time = 0, completed = 0;


    // Step 2: Start Round Robin Loop
    while (completed < n) {
        for (int i = 0; i < n; ++i) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    completion_time[i] = current_time;
                    tat[i] = completion_time[i];  // Arrival time is 0
                    wt[i] = tat[i] - processes[i].burst_time;
                    completed++;
                } else {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
            }
        }
    }

    // Step 3: Print the table
    float awt = 0, atat = 0;
    printf("\n%-10s%-15s%-15s%-20s%-20s%-15s\n",
           "Process ID", "Arrival Time", "Burst Time",
           "Completion Time", "Turnaround Time", "Waiting Time");

    for (int i = 0; i < n; i++) {
        printf("%-10d%-15d%-15d%-20d%-20d%-15d\n",
               processes[i].id, 0, processes[i].burst_time,
               completion_time[i], tat[i], wt[i]);
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", awt / n);
    printf("Average Turnaround Time = %.2f\n", atat / n);
}

int main() {
    // Sample processes
    struct Process processes[] = {{1, 4}, {2, 3}, {3, 5}};
    int n = sizeof(processes) / sizeof(processes[0]);
    int time_quantum = 2;

    printf("Round Robin Scheduling:\n");
    roundRobin(processes, n, time_quantum);
    return 0;
}
