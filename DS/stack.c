#include <stdio.h>

#define SIZE 9

int STACK[SIZE];
int top = -1;

void push(int data){
  if(top == SIZE-1){
    printf("Stack Overflow\n");
    return;
  }
  else{
    top++;
    printf("Push Element: %d\n",data);
    STACK[top] = data;
  }
}

void pop(){
  if(top == -1){
    printf("Stack Underflow\n");
    return;
  }
  else{
    printf("Pop Element: %d\n",STACK[top]);
    top--;
  }
}

int isEmpty(){
  if(top == -1){
    return 1;
  }
  else{
    return 0;
  }
}


int main(){
  int a[12] = {10,20,30,40,50,60,70,80,90,100,110,120};
  for(int i=0; i<12; i++){
    push(a[i]);
  }
  for(int i=0; i<12; i++){
    if(isEmpty()){
      printf("\nStack is Empty");
      continue;
    }
    else{
      pop();
    }
  }

  return 0;
}
