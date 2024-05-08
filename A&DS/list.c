#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node *Nodeptr;
void insertlinkedlist(Nodeptr *top, int data) {
  Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = *top;
  *top = temp;
}

void reverseLinkedList(Nodeptr *top) {
  Nodeptr prev = NULL, current = *top, next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *top = prev;
}
int isReversibleWord(Nodeptr top) {
  Nodeptr temp = top;
  reverseLinkedList(&top);
  while (temp != NULL) {
    if (temp->data != top->data) {
      return 0;
    }
    temp = temp->next;
    top = top->next;
  }
  return 1;
}
int main() {
  Nodeptr top = NULL;
  insertlinkedlist(&top, 'r');
  insertlinkedlist(&top, 'a');
  insertlinkedlist(&top, 'c');
  insertlinkedlist(&top, 'e');
  insertlinkedlist(&top, 'c');
  insertlinkedlist(&top, 'a');
  insertlinkedlist(&top, 'r');
  int result = isReversibleWord(top);
  printf("%s\n", result ? "Yes" : "No");
}
