#include <stdio.h>
#define MAX_SIZE 100

struct process{
  int pid;
  int at;
  int brust_time;
} s1[10], temp;

int waiting[10];
top = -1;
int wl[MAX_SIZE];
int min;
void push(int val)
{
  if (s.empty())
  {
    s.push(val);
    min = val;
  }
else if (val > min) {
    s.push(val);
  }
else {
    s.push(2*val - min);
    min = val;
  }
}

void pop()
{
  if (s.empty()) {
    cout << "Stack underflow!!" << endl;
    exit(-1);
  }

  int top = s.top();
  if (top < min) {
    min = 2*min - top;
  }
  s.pop();
}

int return(){
  int a = pop();
  if(a == -1){
    return 
  }
}

int main(){
  int n,pass=0,swap,i=0;
  printf("Enter the no. of process you want to enter: ");
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    s1[i].pid = i+1;
    printf("Enter the arrival time: ");
    scanf("%d",&s1[i].at);
    printf("Enter the brust time: ");
    scanf("%d", &s1[i].brust_time);
  }

  int wt[n], ft[n], tt[n];

  for(pass=0;pass<n-1;pass++){
    for(i=0;i<n-pass-1;i++){
        if(s1[i].at > s1[i+1].at){
          swap += 1;
          temp = s1[i];
          s1[i] = s1[i+1];
          s1[i+1] = temp;
        }
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=i; j<s1[i].bt; j++){
      if()
      push(s1[j].bt);
    }
  }
  

  for(int i=0; i<n; i++){
    printf("\nPid: %d", s1[i].pid);
    printf("\nArival time: %d", s1[i].at);
    printf("\nBrust time: %d", s1[i].brust_time);
  }
  
  return 0;
}
