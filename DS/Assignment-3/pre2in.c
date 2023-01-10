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

void pre2in(char* str)
{
   int n,i;
   char a,b,op;
   n=strlen(str);
   printf("Prefix - Infix expression is: ");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      {
         op=pop();
         a=str[i];
         printf("%c%c",a,op);
      }
   }
   printf("%c\n",str[top--]);
}

void post2in(char str[])
{
   int n,i,j=0;
   char a,b,op,x[20];
   strrev(str);
   n=strlen(str);
  for(i=0;i<20;i++){
    stack[i]='\0';
  }
   printf("Postfix - Infix expression is: ");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      {
         x[j++]=str[i];
        printf("%c",x[j++]);
         x[j++]=pop();
        printf("%c",x[j++]);
      }
   }
   x[j]=str[top--];
}

int main(){
  char exp[20] = "+E-+DC+BA";
  //strrev(exp);
  pre2in(exp);
  post2in(exp);
  return 0;
}
