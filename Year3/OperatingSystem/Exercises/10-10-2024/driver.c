#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
  char name[10];
  int priority;
  int burst;
  struct Task *next;
} Task;

Task *head = NULL;

void run(char *taskName, int burst) {
  printf("Running task: %s for %d ms\n", taskName, burst);
}
void insert(Task **head, char *name, int priority, int burst) {
  Task *newTask = (Task *)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->burst = burst;
  newTask->next = *head;
  *head = newTask;
}

void scheduleFCFS(Task *head) {
  Task *temp = head;
  while (temp != NULL) {
    run(temp->name, temp->burst);
    temp = temp->next;
  }
}

Task *pickNextTaskSJF(Task *head) {
  Task *temp = head;
  Task *shortest = head;
  while (temp != NULL) {
    if (temp->burst < shortest->burst) {
      shortest = temp;
    }
    temp = temp->next;
  }
  return shortest;
}

Task *pickNextTaskPriority(Task *head) {
  Task *temp = head;
  Task *highestPriority = head;
  while (temp != NULL) {
    if (temp->priority > highestPriority->priority) {
      highestPriority = temp;
    }
    temp = temp->next;
  }
  return highestPriority;
}

void scheduleRR(Task *head, int quantum) {
  Task *temp = head;
  while (temp != NULL) {
    if (temp->burst > quantum) {
      run(temp->name, quantum);
      temp->burst -= quantum;
    } else {
      run(temp->name, temp->burst);
    }
    temp = temp->next;
  }
}

void removeTask(Task **head, Task *taskToRemove) {
  Task *temp = *head, *prev = NULL;

  if (temp != NULL && temp == taskToRemove) {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp != taskToRemove) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
    return;
  prev->next = temp->next;
  free(temp);
}

void insertByPriority(Task **head, char *name, int priority, int burst) {
  Task *newTask = (Task *)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->burst = burst;

  if (*head == NULL || (*head)->priority <= priority) {
    newTask->next = *head;
    *head = newTask;
    return;
  }

  Task *temp = *head;
  while (temp->next != NULL && temp->next->priority > priority) {
    temp = temp->next;
  }
  newTask->next = temp->next;
  temp->next = newTask;
}
void schedulePriorityRR(Task *head, int quantum) {
  for (int priority = 10; priority >= 1; priority--) {
    Task *temp = head;

    while (temp != NULL) {
      if (temp->priority == priority) {
        if (temp->burst > quantum) {
          run(temp->name, quantum);
          temp->burst -= quantum;
        } else {
          run(temp->name, temp->burst);
          removeTask(&head, temp); 
        }
      }
      temp = temp->next;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <schedule_file>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Failed to open file");
    return 1;
  }

  Task *taskList = NULL; 
  char taskName[10];
  int priority, burst;

  while (fscanf(file, "%[^,], %d, %d\n", taskName, &priority, &burst) == 3) {
    insert(&taskList, taskName, priority,
           burst); 
  }
  fclose(file);

  int choice;
  printf("Select scheduling algorithm:\n1. FCFS\n2. SJF\n3. Priority\n4. "
         "Round-Robin\n5. Priority with RR\n");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    scheduleFCFS(taskList);
    break;
  case 2:
    pickNextTaskSJF(taskList);
    break;
  case 3:
    pickNextTaskPriority(taskList);
    break;
  case 4:
    scheduleRR(taskList, 10); 
    break;
  case 5:
    schedulePriorityRR(taskList,
                       10); 
    break;
  default:
    printf("Invalid choice!\n");
    break;
  }

  removeTask(&head, taskList); 

  return 0;
}
