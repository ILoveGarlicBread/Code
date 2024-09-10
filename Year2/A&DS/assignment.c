#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for queue
typedef struct {
  int arr[MAX_SIZE];
  int front;
  int rear;
} Queue;

// Structure for stack
typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

// Function to initialize a queue
Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

// Function to initialize a stack
Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = -1;
  return stack;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) { return (queue->front == -1); }

// Function to check if the queue is full
int isFull(Queue *queue) {
  return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to check if the stack is empty
int isStackEmpty(Stack *stack) { return (stack->top == -1); }

// Function to check if the stack is full
int isStackFull(Stack *stack) { return (stack->top == MAX_SIZE - 1); }

// Function to add an element to the rear of the queue (enqueue)
void enqueue(Queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full. Cannot enqueue.\n");
    return;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
  }
  queue->rear = (queue->rear + 1) % MAX_SIZE;
  queue->arr[queue->rear] = data;
}

// Function to remove an element from the front of the queue (dequeue)
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1;
  }
  int data = queue->arr[queue->front];
  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front = (queue->front + 1) % MAX_SIZE;
  }
  return data;
}

// Function to push an element onto the stack
void push(Stack *stack, int data) {
  if (isStackFull(stack)) {
    printf("Stack is full. Cannot push.\n");
    return;
  }
  stack->top++;
  stack->arr[stack->top] = data;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
  if (isStackEmpty(stack)) {
    printf("Stack is empty. Cannot pop.\n");
    return -1;
  }
  int data = stack->arr[stack->top];
  stack->top--;
  return data;
}

Queue *combineSortedQueues(Queue *Q1, Queue *Q2) {
  Queue *Q3 = createQueue();
  Stack *Q2stack = createStack();
  // converting Q2 to stack
  while (!isEmpty(Q2)) {
    push(Q2stack, dequeue(Q2));
  }
  // Merge operation of Merge Sort
  while (!isEmpty(Q1) && !isStackEmpty(Q2stack)) {
    if (Q1->arr[Q1->front] < Q2stack->arr[Q2stack->top]) {
      enqueue(Q3, dequeue(Q1));
    } else {
      enqueue(Q3, pop(Q2stack));
    }
  }
  while (!isEmpty(Q1)) {
    enqueue(Q3, dequeue(Q1));
  }
  while (!isStackEmpty(Q2stack)) {
    enqueue(Q3, pop(Q2stack));
  }
  free(Q2stack);
  return Q3;
}

void display(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }
  int i = queue->front;
  printf("Queue elements: ");
  do {
    printf("%d ", queue->arr[i]);
    i = (i + 1) % MAX_SIZE;
  } while (i != (queue->rear + 1) % MAX_SIZE);
  printf("\n");
}

int main() {
  Queue *Q1 = createQueue();
  Queue *Q2 = createQueue();
  enqueue(Q1, 1);
  enqueue(Q1, 3);
  enqueue(Q1, 5);
  enqueue(Q1, 7);
  enqueue(Q1, 9);

  enqueue(Q2, 10);
  enqueue(Q2, 8);
  enqueue(Q2, 6);
  enqueue(Q2, 4);
  enqueue(Q2, 2);

  Queue *Q3 = combineSortedQueues(Q1, Q2);

  printf("Combined Sorted Queue Q3: ");
  display(Q3);

  free(Q1);
  free(Q2);
  free(Q3);

  return 0;
}

