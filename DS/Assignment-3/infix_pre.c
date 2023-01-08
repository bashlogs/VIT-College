#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char stack[100];
int top = -1;

void push(char x){
  stack[++top] = x;
}

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

char pop(){
  if(top == -1)
    return -1;
  else
    return stack[top--];
}

int priority(char x){
  if(x == '+' || x == '-')
    return 1;
  if(x == '*' || x == '/')
    return 2;
  else
    return 0;
}

char* infix2pre(char* infix) {
  int i, j;
  char *e;
  e = infix;
  int n = strlen(infix);
  char* prefix = (char*) malloc(n + 1);
  while(*e != '\0') {
    if (*e == '(') {
      push(*e);
    } else if (*e == ')') {
      while (stack[top] != '(') {
        prefix[j++] = pop();
      }
      pop();
    } else if (isalpha(*e)) {
      prefix[j++] = *e;
    } else {
      while (priority(stack[top]) >= priority(*e)) {
        prefix[j++] = pop();
      }
      push(*e);
    }
    e++;
  }
  while (top != -1) {
    prefix[j++] = pop();
  }
  prefix[j] = '\0';
  return strrev(prefix);
}

char* infix2pre1(char* infix){
  char *e, x=0, c;
  e = infix;
  int n=strlen(infix);
  char* prefix = (char*)malloc(n+1);
  while(*e != '\0'){
    if(isalpha(*e)){
      prefix[x++] = *e;
    }
    else if(*e == '('){
      push(*e);
    }
    else if(*e == ')'){
      while(stack[top] != '('){
        prefix[x++] = pop();
      }
      pop();
    }
    else{
      while(priority(stack[top]) >= priority(*e))
        prefix[x++] = pop();
      push(*e);
    }
    e++;
  }
  while (top != -1) {
    prefix[x++] = pop();
  }
  prefix[x] = '\0';
  return strrev(prefix);
}


int main(){
  char exp[20] = "A+B-(C+D)+E";
  printf(infix2pre1(exp));
  return 0;
}
