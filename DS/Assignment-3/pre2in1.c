#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char *c) {
  if (top == MAX_SIZE - 1) {
    printf("Error: stack overflow\n");
  } else {
    stack[++top] = *c;
  }
}

char pop() {
  if (top == -1) {
    printf("Error: stack underflow\n");
    return '\0';
  } else {
    return stack[top--];
  }
}

char* prefix_to_infix(char* prefix) {
  int i;
  int n = strlen(prefix);
  char* infix = (char*) malloc(2 * n + 1);
  for (i = n - 1; i >= 0; i--) {
    if (isalpha(prefix[i])) {
      char data = prefix[i];
      push(data);
    } 
    else {
      char operand1[2] = { pop(), '\0' };
      char operand2[2] = { pop(), '\0' };
      sprintf(infix, "(%s%c%s)", operand1, prefix[i], operand2);
      push(infix);
    }
  }
  return infix;
}

int main() {
  char prefix[] = "*-A/BC-/AKL";
  printf("Prefix expression: %s\n", prefix);
  printf("Infix expression: %s\n", prefix_to_infix(prefix));
  return 0;
}
