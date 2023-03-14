#include <stdio.h>
  
int main() 
{
      int at[10], bt[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, tt = 0, end;
      float average_waiting_time, average_tt;
      printf("\nEnter the Total Number of Processes: ");
      scanf("%d", &limit); 
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time: ");
            scanf("%d", &at[i]);
            printf("Enter Burst Time: ");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
      }
      bt[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
                  {
                        smallest = i;
                  }
            }
            bt[smallest]--;
            if(bt[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - at[smallest] - temp[smallest];
                  tt = tt + end - at[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_tt = tt / limit;
      printf("\n\nAverage Waiting Time:%lf\n", average_waiting_time);
      printf("Average Turnaround Time:%lf\n", average_tt);
      return 0;
}
