#include <stdio.h>
#include <stdbool.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int num_processes;
int num_resources;
int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finished[MAX_PROCESSES];

void calculate_need_matrix()
{
for (int i = 0; i < num_processes; i++)
{
for (int j = 0; j < num_resources; j++)
{
need[i][j] = max[i][j] - allocation[i][j];
}
}
}
bool is_safe_state(int process)
{
int work[MAX_RESOURCES];
bool finish[num_processes];
for (int i = 0; i < num_resources; i++)
{
work[i] = available[i];
}
for (int i = 0; i < num_processes; i++)
{
finish[i] = finished[i];
}
finish[process] = true;
bool found = true;
while (found)
{
found = false;
for (int i = 0; i < num_processes; i++)
{
if (!finish[i])
{
bool can_run = true;
for (int j = 0; j < num_resources; j++)
{
if (need[i][j] > work[j])
{
can_run = false;
break;
}
}
if (can_run)
{
for (int j = 0; j < num_resources; j++)
{
work[j] += allocation[i][j];
}
finish[i] = true;
found = true;
}
}
}
}
for (int i = 0; i < num_processes; i++)
{
if (!finish[i])
{
return false;
}
}
return true;
}
bool is_resource_available(int request_process, int request[])
{
for (int i = 0; i < num_resources; i++)
{
if (request[i] > available[i])
{
return false;
}
}
return true;
}
bool is_request_granted(int request_process, int request[])
{
if (!is_resource_available(request_process, request))
{
return false;
}
for (int i = 0; i < num_resources; i++)
{
available[i] -= request[i];
allocation[request_process][i] += request[i];
need[request_process][i] -= request[i];
}
if (is_safe_state(request_process))
{
return true;
}
else
{
for (int i = 0; i < num_resources; i++)
{
available[i] += request[i];
allocation[request_process][i] -= request[i];
need[request_process][i] += request[i];
}
return false;
}
}
void print_need_matrix()
{
printf("\nNeed Matrix:\n");
for (int i = 0; i < num_processes; i++)
{
for (int j = 0; j < num_resources; j++)
{
printf("%d ", need[i][j]);
}
printf("\n");
}
}
int main()
{
printf("Enter the number of processes: ");
scanf("%d", &num_processes);
printf("Enter the number of resources: ");
scanf("%d", &num_resources);
printf("Enter the available vector: ");
for (int i = 0; i < num_resources; i++)
{
scanf("%d", &available[i]);
}
printf("Enter the Max matrix:\n");
for (int i = 0; i < num_processes; i++)
{
for (int j = 0; j < num_resources; j++)
{
scanf("%d", &max[i][j]);
}
}
printf("Enter the Allocation matrix:\n");
for (int i = 0; i < num_processes; i++)
{
for (int j = 0; j < num_resources; j++)
{
scanf("%d", &allocation[i][j]);
}
}
calculate_need_matrix();
print_need_matrix();

printf("\nChecking for safe state...\n");
int safe_sequence[MAX_PROCESSES];
int num_finished = 0;
bool safe = true;
while (num_finished < num_processes)
{
bool found = false;
for (int i = 0; i < num_processes; i++)
{
if (!finished[i] && is_safe_state(i))
{
for (int j = 0; j < num_resources; j++)
{
available[j] += allocation[i][j];
}
safe_sequence[num_finished] = i;
finished[i] = true;
num_finished++;
found = true;
break;
}
}
if (!found)
{
safe = false;
break;
}
}
if (safe)
{
printf("\nThe system is in a safe state.\nSafe Sequence: ");
for (int i = 0; i < num_processes; i++)
{
printf("%d ", safe_sequence[i]);
}
printf("\n");
}
else
{
printf("\nThe system is in an unsafe state.\n");
}

printf("\nResource Request Algorithm\n");
int request_process;
int request[MAX_RESOURCES];
printf("\nEnter the process index for the new request: ");
scanf("%d", &request_process);
printf("Enter the request vector: ");
for (int i = 0; i < num_resources; i++)
{
scanf("%d", &request[i]);
}
if (is_request_granted(request_process, request))
{
printf("The request can be granted.\n");
}
else
{
printf("The request cannot be granted.\n");
}
return 0;
}