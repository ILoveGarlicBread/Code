// Filename: test.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
  int data;
  struct node *next;
};
struct node *head = NULL;
void reversedList();
void insertBeginning(int n);
void insertEnd(int n);
void displayStruct();
int countNodes();
void insertAtNth(int n, int position);
void deleteNthNode(int position);
void deleteEnd();
int searchData(int position);
char *toString();

int main() {
  int num, data, position;
  printf("Input number of nodes: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    printf("Input data for node %d: ", i + 1);
    scanf("%d", &data);
    insertEnd(data);
  }
  displayStruct();
  printf("Linked list in string format: %s", toString());
  printf("\n");
  return 0;
}

char *toString() {
  char *string = malloc(100 * sizeof(char));
  struct node *temp = head;
  int i = 0;
  while (temp != NULL) {
    sprintf(string + i, "%d ", temp->data);
    temp = temp->next;
    i += strlen(string + i);
  }
  return string;
}

void insertBeginning(int num) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = head;
  head = newNode;
}

void insertAtNth(int num, int position) {
  struct node *newNode = malloc(sizeof(struct node));
  struct node *temp = head;
  newNode->data = num;
  newNode->next = NULL;
  position--;
  while (position != 1) {
    temp = temp->next;
    position--;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void insertEnd(int num) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;
  if (head == NULL)
    head = newNode;
  else {
    struct node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void deleteNthNode(int position) {
  struct node *temp = head;
  struct node *previous;
  if (head == NULL) {
    printf("No node in list.");
  } else {
    if (position == 1) {
      head = temp->next;
      free(temp);
      return;
    }
    while (position != 1) {
      previous = temp;
      temp = temp->next;
      position--;
    }
    previous->next = temp->next;
    free(temp);
  }
}

void deleteEnd() {
  struct node *temp = head;
  struct node *previous;
  while (temp->next != NULL) {
    previous = temp;
    temp = temp->next;
  }
  previous->next = NULL;
  free(temp);
}
int searchData(int position) {
  struct node *temp = head;
  while (position != 1) {
    temp = temp->next;
    position--;
  }
  return temp->data;
}

void reversedList() {
  struct node *previous = NULL, *current = head, *nextNode = NULL;
  while (current != NULL) {
    nextNode = current->next;
    current->next = previous;
    previous = current;
    current = nextNode;
  }
  head = previous;
}

int countNodes() {
  int counter = 0;
  struct node *temp = head;
  while (temp != NULL) {
    counter++;
    temp = temp->next;
  }
  return counter;
}

void displayStruct() {
  struct node *temp = head;
  while (temp != NULL) {
    printf("[%d]->", temp->data);
    temp = temp->next;
  }
  printf("NULL");
  printf("\n");

  if (temp == NULL) {
    return;
  }
  printf("[%d|%p]->", temp->data, temp);
  temp = temp->next;
  displayStruct();
}
