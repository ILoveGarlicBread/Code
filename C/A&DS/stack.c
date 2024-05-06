#include <ctype.h> // For isdigit function
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack node
struct StackNode {
  int data;
  struct StackNode *next;
};

// Function to create a new stack node
struct StackNode *createNode(int data) {
  struct StackNode *newNode =
      (struct StackNode *)malloc(sizeof(struct StackNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode *root) { return !root; }

// Function to push an element onto the stack
void push(struct StackNode **root, int data) {
  struct StackNode *newNode = createNode(data);
  newNode->next = *root;
  *root = newNode;
}

// Function to pop an element from the stack
int pop(struct StackNode **root) {
  if (isEmpty(*root)) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  }
  struct StackNode *temp = *root;
  *root = (*root)->next;
  int popped = temp->data;
  free(temp);
  return popped;
}
void decimalToBinary(int n) {
  struct StackNode *stack = NULL;
  while (n > 0) {
    push(&stack, n % 2);
    n /= 2;
  }
  while (!isEmpty(stack)) {
    printf("%d", pop(&stack));
  }
}
int areSymbolsBalanced(char *exp) {
  struct StackNode *stack = NULL;
  int i = 0;
  while (exp[i]) {
    if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
      push(&stack, exp[i]);
    } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
      if (isEmpty(stack)) {
        return 0; // Unbalanced: no opening symbol to match
      }
      char top = pop(&stack);
      if ((exp[i] == ')' && top != '(') || (exp[i] == ']' && top != '[') ||
          (exp[i] == '}' && top != '{')) {
        return 0; // Unbalanced: mismatched symbols
      }
    }
    i++;
  }
  return isEmpty(stack); // Balanced if stack is empty
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
  struct StackNode *stack = NULL;
  int i = 0;
  while (exp[i]) {
    if (isdigit(exp[i])) {
      push(&stack, exp[i] - '0');
      printf("%d\n", exp[i] - '0');

    } else {
      int val1 = pop(&stack);
      int val2 = pop(&stack);
      switch (exp[i]) {
      case '+':
        push(&stack, val2 + val1);
        printf("%d\n", val2 + val1);
        break;
      case '-':
        push(&stack, val2 - val1);
        printf("%d\n", val2 - val1);
        break;
      case '*':
        push(&stack, val2 * val1);
        printf("%d\n", val2 * val1);
        break;
      case '/':
        push(&stack, val2 / val1);
        printf("%d\n", val2 / val1);
        break;
      }
    }
    i++;
  }
  return pop(&stack);
}

// Example usage
int main() {
  char exp2[] = "{(2 + 3) * [1 - 5]}"; // Balanced
  char exp3[] = "(2 + 3) * [1 - 5])";  // Unbalanced

  printf("%s is %s\n", exp2,
         areSymbolsBalanced(exp2) ? "balanced" : "not balanced");
  printf("%s is %s\n", exp3,
         areSymbolsBalanced(exp3) ? "balanced" : "not balanced");

  char exp[] = "562+*124:-";
  printf("Postfix expression evaluation: %d\n", evaluatePostfix(exp));
  return 0;
}
