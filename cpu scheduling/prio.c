#include <stdio.h>
#include <limits.h>

// Define a structure for Process
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int is_completed;
} Process;

// Function to sort processes by arrival time
void sort_by_arrival_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Priority Scheduling (Non-Preemptive)
void priority_scheduling(Process processes[], int n) {
    int current_time = 0, completed = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    sort_by_arrival_time(processes, n);

    while (completed < n) {
        int highest_priority_index = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].is_completed == 0) {
                if (processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    highest_priority_index = i;
                }
            }
        }

        if (highest_priority_index == -1) {
            current_time++; // CPU is idle
        } else {
            Process *p = &processes[highest_priority_index];
            p->completion_time = current_time + p->burst_time;
            p->turnaround_time = p->completion_time - p->arrival_time;
            p->waiting_time = p->turnaround_time - p->burst_time;
            current_time = p->completion_time;
            p->is_completed = 1;
            completed++;

            total_waiting_time += p->waiting_time;
            total_turnaround_time += p->turnaround_time;
        }
    }

    // Display the results
    printf("%-10s%-15s%-15s%-15s%-20s%-20s%-15s\n",
           "ProcessID", "ArrivalTime", "BurstTime", "Priority",
           "CompletionTime", "TurnaroundTime", "WaitingTime");

    for (int i = 0; i < n; i++) {
        printf("%-10d%-15d%-15d%-15d%-20d%-20d%-15d\n",
               processes[i].process_id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].priority,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

// Main function
int main() {
    Process processes[] = {
        {1, 0, 4, 1, 0, 0, 0, 0},
        {2, 0, 2, 2, 0, 0, 0, 0},
        {3, 6, 7, 1, 0, 0, 0, 0},
        {4, 11, 2, 2, 0, 0, 0, 0},
        {5, 12, 4, 3, 0, 0, 0, 0}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Priority Scheduling (Non-Preemptive):\n\n");
    priority_scheduling(processes, n);

    return 0;
}
