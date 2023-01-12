#include <stdio.h>

void FT(int processes[], int n, int bt[]){
  int wt[n], tat[n], total_wt = 0, total_tat = 0, fn[n];
  for(int i=0; i<n; i++){
    fn[i] = fn[i-1]+bt[i];
  }
  for(int i=0;i<n;i++){
    tat[i] = fn[i]-processes[i];
  }
  for(int i=0;i<n;i++){
    wt[i] = tat[i] - bt[i];
  }
  
  printf("Arival Time: ");
  for(int i=0; i<n; i++){
    printf("%d\t",processes[i]);
  }
  printf("\nBrust Time: ");
  for(int i=0; i<n; i++){
    printf("%d\t",bt[i]);
  }
  printf("\nFinish Time: ");
  for(int i=0; i<n; i++){
    printf("%d\t",fn[i]);
  }
  printf("\nTurn Around Time: ");
  for(int i=0; i<n; i++){
    printf("%d\t",tat[i]);
  }
  printf("\nWaiting Time: ");
  for(int i=0; i<n; i++){
    printf("%d\t",wt[i]);
  }
}
int main(){
  int processes[] = {0,2,3,4,5};
  int n = sizeof(processes) / sizeof(processes[0]);
  int bt[] = {9,1,3,2,5};
  FT(processes, n, bt);
}
