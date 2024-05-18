
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
  int coef;
  int exp;
  struct node *next;
};
typedef struct node *nodeptr;

nodeptr insertEnd(nodeptr head, int coef, int exp) {
  nodeptr new_node = (nodeptr)malloc(sizeof(struct node));
  new_node->coef = coef;
  new_node->exp = exp;
  new_node->next = NULL;
  if (head == NULL) {
    return new_node;
  }
  
  nodeptr current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

nodeptr addpoly(nodeptr poly1, nodeptr poly2) {
  nodeptr result = NULL;
  while (poly1 != NULL && poly2 != NULL) {
    if (poly1->exp > poly2->exp) {
      result = insertEnd(result, poly1->coef, poly1->exp);
      poly1 = poly1->next;
    } else if (poly1->exp < poly2->exp) {
      result = insertEnd(result, poly2->coef, poly2->exp);
      poly2 = poly2->next;
    } else {
      result = insertEnd(result, poly1->coef + poly2->coef, poly1->exp);
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
  }
  while (poly1 != NULL) {
    insertEnd(result, poly1->coef, poly1->exp);
    poly1 = poly1->next;
  }
  while (poly2 != NULL) {
    insertEnd(result, poly2->coef, poly2->exp);
    poly2 = poly2->next;
  }

  return result;
}
int main() {
  nodeptr poly1 = NULL;
  poly1 = insertEnd(poly1, 3, 2);
  poly1 = insertEnd(poly1, 2, 1);
  poly1 = insertEnd(poly1, 1, 0);

  nodeptr poly2 = NULL;
  poly2 = insertEnd(poly2, 4, 3);
  poly2 = insertEnd(poly2, 1, 1);

  nodeptr result = addpoly(poly1, poly2);

  printf("Resultant polynomial: ");
  nodeptr current = result;
  while (current != NULL) {
    printf("%dx^%d ", current->coef, current->exp);
    current = current->next;
    if (current != NULL) {
      printf("+ ");
    }
  }
  printf("\n");

  // Free the memory allocated for the lists
  while (result != NULL) {
    nodeptr temp = result;
    result = result->next;
    free(temp);
  }
  while (poly1 != NULL) {
    nodeptr temp = poly1;
    poly1 = poly1->next;
    free(temp);
  }
  while (poly2 != NULL) {
    nodeptr temp = poly2;
    poly2 = poly2->next;
    free(temp);
  }

  return 0;
}
