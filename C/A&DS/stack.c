#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
  int data;
  struct Stack *next;
};
typedef struct Stack *nodeptr;

void push(nodeptr *top, int num) {
  nodeptr newNode = (nodeptr)malloc(sizeof(struct Stack));
  newNode->data = num;
  newNode->next = *top;
  *top = newNode;
}
void pop(nodeptr *top) {
  nodeptr temp = *top;
  *top = (*top)->next;
  free(temp);
}
void printstack(nodeptr top) {
  while (top != NULL) {
    printf("%d\n", top->data);
    top = top->next;
  }
}
void decimaltobinary(int num) {
  nodeptr stack = NULL;
  while (num > 0) {
    push(&stack, num % 2);
    num = num / 2;
  }
  while (stack != NULL) {
    printf("%d", stack->data);
    stack = stack->next;
  }
}
void postfixOp(char *postfix) {
  nodeptr stack = NULL;
  while (*postfix != '\0')
    if (isdigit(*postfix)) {
      push(&stack, *postfix - '0');
    } else if (*postfix == '+' || *postfix == '-' || *postfix == '*' ||
               *postfix == '/') {
      printf("log\n");
      int num1 = stack->data;
      printf("log2\n");
      pop(&stack);
      int num2 = stack->data;
      pop(&stack);
      int num3 = 0;
      switch (*postfix) {
      case '+':
        num3 = num1 + num2;
        break;
      case '-':
        num3 = num1 - num2;
        break;
      case '*':
        num3 = num1 * num2;
        break;
      case '/':

        num3 = num1 / num2;
        break;
      }
    }
}

int main() {
  // int num;
  // printf("Enter the number\n");
  // scanf("%d", &num);
  // decimaltobinary(num);
  char math[] = "ab+";
  postfixOp(math);
  printf("\n");
  return 0;
}
