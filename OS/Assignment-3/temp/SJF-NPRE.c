#include <stdio.h>
#define MAX_SIZE 10

struct process{
  int pid;
  int at;
  int brust_time;
  int ft;
  int tt;
  int wt;
} s1[10], temp;

int top = -1;
int wl[MAX_SIZE];

void push(int val)
{
  wl[++top] = val;
}

int pop()
{
  int pass, swap, temp;
  if(top == -1){
    return 0;
  }
  else{
    for(pass=0;pass<MAX_SIZE-1;pass++)
    {
      for(int i=0;i<MAX_SIZE-pass-1;i++)
      {
        if(wl[i] < wl[i+1]){
          swap += 1;
          temp = wl[i];
          wl[i] = wl[i+1];
          wl[i+1] = temp;
        }
      }
    }
    return wl[top--];
  }
}

int pos = 1;

void processes(struct process *s2, int n){
  int x[10],tt,ft,wt,swap;
  for(int i=0; i<n; i++){
    if(top < -1){
      for(int data=0;data<top;data++){
        x[data] = pop();
      }
      int size = sizeof(x)/sizeof(x[0]);
      for(int pass=0;pass<n-1;pass++){
        for(i=0;i<size-pass-1;i++){
            if(x[i] > x[i+1]){
              swap += 1;
              temp = s1[i];
              s1[i] = s1[i+1];
              s1[i+1] = temp;
            }
        }
      }

    }
    else{
      for(int j=0; j<s2[n].brust_time; j++){
        if(j=s2[pos].at){
          push(s2[pos].pid);
          pos += 1;
        }
        ft += 1;
      }
      s2[n].ft = ft;
      s2[n].tt = tt;
      s2[n].wt = wt;
    }

  }
}

int main(){
  int n,pass=0,swap,i=0, tt, wt, total_time = 0;
  printf("Enter the no. of process you want to enter: ");
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    s1[i].pid = i+1;
    printf("Enter the arrival time: ");
    scanf("%d",&s1[i].at);
    printf("Enter the brust time: ");
    scanf("%d", &s1[i].brust_time);
  }
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
  int waiting;
  // for(int i=0; i<n; i++){
  //   if(waiting = pop()){
  //     printf("IDK");
  //     // s1[waiting];
  //     // for(int j=i;j<s1[waiting].brust_time; j++){
  //     //   if(j == s1[])
  //     // }
  //   }
  //   else{
  //     for(int j=i; j<=s1[i].brust_time; j++){
  //       if(j == s1[j].at){
  //         push(s1[i].pid);
  //       }
  //       else{
  //         total_time = total_time + j;
  //       }
  //     }
  //     tt[i] = total_time;
  //   }
  // }


  processes(*s1,n);

  for(int i=0; i<n; i++){
    printf("\nPid: %d", s1[i].pid);
    printf("\nArival time: %d", s1[i].at);
    printf("\nBrust time: %d", s1[i].brust_time);
    printf("\nFinish time: %d", s1[i].brust_time);
    printf("\nTurn Around time: %d", s1[i].brust_time);
    printf("\nWaiting time: %d", s1[i].brust_time);
  }
  
  return 0;
}
