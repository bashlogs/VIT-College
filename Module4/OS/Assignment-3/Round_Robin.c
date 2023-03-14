#include <stdio.h>

int main()
{
    int i, n, time, remain, flag = 0, tq = 1;
    int wt = 0, tt = 0, ft[10], rt[10];
    int at[] = {0,1,3,3};
    int bt[] = {1,9,1,9};
    n = sizeof at / sizeof at[0];
    remain = n;

    for (int i = 0; i < n; i++){
        rt[i] = bt[i];
    }
    
    printf("AT\t BT\t FT\t TAT\t WT");
    for (time = 0, i = 0; remain != 0;){
        if (rt[i] <= tq && rt[i] > 0){
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }else if (rt[i] > 0){
            rt[i] -= tq;
            time += tq;
        }
        if (rt[i] == 0 && flag == 1){
            remain--;
            ft[i] = time;
            printf("\n%d\t %d\t %d\t %d\t %d", at[i],bt[i], ft[i], ft[i] - at[i], ft[i] - at[i] - bt[i]);

            wt += ft[i] - at[i] - bt[i];
            tt += ft[i] - at[i];
            flag = 0;
        }
        if (i == n - 1){
            i = 0; 
        } else if (at[i + 1] <= time){
            i++;
        } else{ i = 0; }
    }

    printf("\n\nAverage WT:  %0.2f", (wt * 1.0 / n));
    printf("\nAverage TAT: %0.2f\n", (tt * 1.0 / n));

    return 0;
}
