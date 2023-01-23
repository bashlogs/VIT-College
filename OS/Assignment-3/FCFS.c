#include <stdio.h>

void fn(int processes[], int n, int bt[]){
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

  printf("AT\t\tBT\t\tfn\t\tatAT\t\tWT\n");
  for(int i=0; i<n; i++){
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], fn[i], tat[i], wt[i]);
  }
  float avg_wt = 0.0, avg_tat = 0.0;
  for (int i = 0; i < n; i++) {
    avg_wt += wt[i];
    avg_tat += tat[i];
  }
  avg_wt /= n;
  avg_tat /= n;

  printf("\nAverage WT:  %0.2f", avg_wt);
  printf("\nAverage TAT: %0.2f\n", avg_tat);

}
int main(){
  int processes[] = {0,2,3,4,5};
  int n = sizeof(processes) / sizeof(processes[0]);
  int bt[] = {9,1,3,2,5};
  fn(processes, n, bt);
}
