#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i, j, n;
    int p[30], bt[30], pr[30], tat[30], wt[30];
    int tot_tat = 0, tot_wt = 0;
    float avg_tat, avg_wt;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter burst time and priority of process[%d]: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                swap(&pr[i], &pr[j]);
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    tot_tat = tat[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
    }

    avg_wt = (float)tot_wt / n;
    avg_tat = (float)tot_tat / n;

    printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\n\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);

    return 0;
}
