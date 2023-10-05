 #include<stdio.h>
#include<stdlib.h>

struct Process {
  int pid;
  int arrivalTime;
  int burstTime;
  int remainingTime;
  int waitingTime;
  int turnaroundTime;
};

void roundrobinscheduling(struct Process processes[], int n, int timeQuantum) {
  
  int currentTime = 0;
  int completedProcesses = 0;
int quntumCounter = 0;

  while (completedProcesses < n) {

  for (int i = 0; i < n; i++) {
  if (processes[i].remainingTime > 0) {
  if ( processes[i].remainingTime <= timeQuantum) {
 currentTime += processes[i].remainingTime;
 processes[i].remainingTime = 0;
 processes[i].turnaroundTime = currentTime - processes[i].arrivalTime;
processes[i].waitingTime=processes[i].turnaroundTime - processes[i].burstTime;
completedProcesses++;
  }else{
	currentTime += timeQuantum;
processes[i].remainingTime -= timeQuantum;
  }
  }
}
quntumCounter++;
}
}
  

int main() {
  int n,timeQuantum;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct Process processes[n];

  for (int i = 0; i < n; i++) {
  printf("Enter arrival time %d: ", i + 1);
  scanf("%d", &processes[i].arrivalTime);
printf("Enter burst time %d: ", i + 1);
scanf("%d", &processes[i].burstTime);
  processes[i].pid = i + 1;
  processes[i].remainingTime = processes[i].burstTime;
  }

printf("Enter the time quantum : ");
scanf("%d",&timeQuantum);

roundrobinscheduling(processes,n,timeQuantum);

  printf("\nGantt Chart:\n");
  for (int i = 0; i < n; i++) {
  printf("| P%d ", processes[i].pid);
  }
  printf("|\n");

  printf("\nProcess\tTurnaround Time\tWaiting Time\n");
  float total_waitingTime = 0;
  float total_turnaroundTime = 0;
  for (int i = 0; i < n; i++) {
  printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].turnaroundTime, processes[i].waitingTime);
  total_waitingTime += processes[i].waitingTime;
  total_turnaroundTime += processes[i].turnaroundTime;
  }

  float average_waiting_time = total_waitingTime / n;
  float average_turnaround_time = total_turnaroundTime / n;

  printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
  printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

  return 0;
}
