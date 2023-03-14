#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void push(char c) {
  if (top == MAX_SIZE - 1) {
    printf("Error: stack overflow\n");
  } else {
    stack[++top] = c;
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

int precedence(char c) {
  switch (c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
  }
}

char* infix_to_prefix(char* infix) {
  int i, j;
  int n = strlen(infix);
  char* prefix = (char*) malloc(n + 1);
  for (i = 0, j = 0; i < n; i++) {
    if (infix[i] == '(') {
      push(infix[i]);
    } else if (infix[i] == ')') {
      while (stack[top] != '(') {
        prefix[j++] = pop();
      }
      pop();
    } else if (isalpha(infix[i])) {
      prefix[j++] = infix[i];
    } else {
      while (precedence(stack[top]) >= precedence(infix[i])) {
        prefix[j++] = pop();
      }
      push(infix[i]);
    }
  }
  while (top != -1) {
    prefix[j++] = pop();
  }
  prefix[j] = '\0';
  return strrev(prefix);
}

int main() {
  char infix[] = "A*B-(C+D)+E";
  printf("Infix expression: %s\n", infix);
  printf("Prefix expression: %s\n", infix_to_prefix(infix));
  return 0;
}
