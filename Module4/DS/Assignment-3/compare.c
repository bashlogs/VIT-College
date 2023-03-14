#include <stdio.h>
#include <string.h>
#define MAX 100
int top=-1;
char stack[MAX];

void push(char item)
{
    if(top == MAX-1)
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    stack[++top]=item;
}

char pop()
{
    if(top == -1)
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }
    return stack[top--];
}

void compare(char data[], char data2[]){
  for(int i=0; i<strlen(data);i++){
    push(data[i]);
  }
  for(int i=0; i<strlen(data2); i++){
    push(data2[i]);
  }
  for(int i=length-1; i>=0; i--){
    new[i] = pop();
  }
}

int main(){
  char str[MAX];
  char str1[MAX];
  printf("Enter first string: ");
  scanf("%s",str);
  printf("Enter second string: ");
  scanf("%s",str1);
  //concat(str,str1);
}
