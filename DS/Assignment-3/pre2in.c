#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[20];
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

void pre2in(char *prefix){
  char *e, op, a;
  e = prefix;
  int n = strlen(prefix);
  char* data = (char*)malloc(2*n+1);
  printf("Infix Expression is: ");
  for(int i=0;i<n;i++){

      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/'){
        char x[2] = {pop(), '\0'};
        char x1[2] = {pop(), '\0'};
        sprintf(data, "(%s%c%s)",x1,e[i],x);
        printf("%s\n", data);
        push(data[0]);
      }
      else{
        push(e[i]);
        //op=pop();
        //a=e[i];
        
        //printf("%c%c",a,op);
      }
    }
  printf("%s",pop());
  }
int main(){
  char exp[20] = "+E-+DC+BA";
  strrev(exp);
  pre2in(exp);
  return 0;
}
