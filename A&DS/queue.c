#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for queue
typedef struct {
  int arr[MAX_SIZE];
  int front;
  int rear;
} Queue;

// Function to initialize a queue
Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) { return (queue->front == -1); }

// Function to check if the queue is full
int isFull(Queue *queue) {
  return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to add an element to the rear of the queue (enqueue)
void enqueue(Queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full. Cannot enqueue.\n");
    return;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
    queue->rear = 0;
  } else {
    queue->rear = (queue->rear + 1) % MAX_SIZE;
  }
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

// Function to get the front element of the queue without removing it
int front(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return -1;
  }
  return queue->arr[queue->front];
}

// Function to display the elements of the queue
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
  Queue *queue = createQueue();

  enqueue(queue, 3);
  enqueue(queue, 5);
  enqueue(queue, 2);
  enqueue(queue, 15);
  enqueue(queue, 42);

  dequeue(queue);
  dequeue(queue);
  enqueue(queue, 14);
  enqueue(queue, 7);
  dequeue(queue);
  enqueue(queue, 9);
  dequeue(queue);
  dequeue(queue);
  enqueue(queue, 51);
  dequeue(queue);
  dequeue(queue);

  display(queue);

  free(queue);

  return 0;
}
