#include <stdio.h>
#define size 10

int s[10];
int top = -1;
int min;

void push(int val)
{
  if (top == -1)
  {
    s[++top] = val;
    min = val;
  }
else if (val > min) {
    s[++top] = val;
  }
else {
    s[++top] = 2*val-min;
    min = val;
  }
}

void getMin() {
  printf("%d\n",min);
  for(int i=0; i<size; i++){
    printf("%d\n",s[i]);
  }
}

int main(){
  push(10);
  push(32);
  push(4);
  push(3);
  getMin();
  return 0;
}
