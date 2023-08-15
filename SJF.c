#include <stdio.h>
int main()
{
    int time, bt[10], at[10], sumbt = 0, smallest, n, i;
    int sumt = 0, sumw = 0;
    printf("enter the no of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("the arrival time for process P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("the burst time for process P%d : ", i + 1);
        scanf("%d", &bt[i]);
        sumbt += bt[i];
    }
    bt[9] = 9999;
    for (time = 0; time < sumbt;)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && bt[i] > 0 && bt[i] < bt[smallest])
                smallest = i;
        }
        printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + bt[smallest] - at[smallest], time - at[smallest]);
        sumt += time + bt[smallest] - at[smallest];
        sumw += time - at[smallest];
        time += bt[smallest];
        bt[smallest] = 0;
    }
    printf("\n\n average waiting time = %f", sumw * 1.0 / n);
    printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
    return 0;
}
/*
enter the no of processes : 5
the arrival time for process P1 : 2
the burst time for process P1 : 1
the arrival time for process P2 : 1
the burst time for process P2 : 5
the arrival time for process P3 : 4
the burst time for process P3 : 1
the arrival time for process P4 : 0
the burst time for process P4 : 6
the arrival time for process P5 : 2
the burst time for process P5 : 3
P[4]    |       6       |       0
P[1]    |       5       |       4
P[3]    |       4       |       3
P[5]    |       9       |       6
P[2]    |       15      |       10


 average waiting time = 4.600000

 average turnaround time = 7.800000
 */