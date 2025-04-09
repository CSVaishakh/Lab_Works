FCFS
#include <stdio.h>
void main() {
    int p[30], bt[30], tot_tat = 0, wt[30], n, tot_wt = 0, tat[30];
    float avg_tat, avg_wt;
    int i;
    printf("\nEnter the No. of Processes: \n");
    scanf("%d", &n);
    printf("Enter Burst time for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    printf("\nFCFS Algorithm \n");
    for(i = 0; i < n; i++) {
        if(i == 0)
            tat[i] = bt[i];
        else
            tat[i] = tat[i - 1] + bt[i];
        
        tot_tat += tat[i];
    }
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tot_wt += wt[i];
    }
    printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
    for(i = 0; i < n; i++) {
        printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], tat[i], wt[i]);
    }
    avg_tat = (float)tot_tat / n;
    printf("\n\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    avg_wt = (float)tot_wt / n;
    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
}


SJF
#include <stdio.h>
void swap(int *a, int *b);
int main() {
    int i, j, n, tot_tat = 0, tot_wt = 0;
    int p[30], bt[30], tat[30], wt[30];
    float avg_tat, avg_wt;
    printf("Enter the no.of processes: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
            }
        }
    }
    for(i = 0; i < n; i++) {
        tat[i] = (i == 0) ? bt[i] : tat[i - 1] + bt[i];
        tot_tat += tat[i];
    }
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tot_wt += wt[i];
    }
    printf("\nPROCESS\tBURST TIME\tTURNAROUND TIME\tWAITING TIME\n");
    for(i = 0; i < n; i++)printf("P[%d]\t\t%d\t\t%d\t\t%d\n", p[i] + 1, bt[i], tat[i], wt[i]);
    avg_tat = (float)tot_tat / n;
    avg_wt = (float)tot_wt / n;
    printf("\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    return 0;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


Priority
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




BestFit
#include <stdio.h>
#define max 25
int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest;
    int bf[max], ff[max];
    printf("\n\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nf; i++) {
        lowest = 10000;
        ff[i] = 0;
        frag[i] = 0;
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) {
                    if (lowest > temp) {
                        ff[i] = j;
                        lowest = temp;
                        frag[i] = temp;
                    }
                }
            }
        }
        if (ff[i] != 0) {
            bf[ff[i]] = 1;
        }
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nf; i++) {
        if (ff[i] != 0) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        }
    }
    return 0;
}



FirstFit
#include <stdio.h>
#define max 25
int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];
    printf("\n\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nf; i++) {
        ff[i] = 0;
        frag[i] = 0;
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) {
                    ff[i] = j;
                    frag[i] = temp;
                    bf[j] = 1;
                    break;
                }
            }
        }
    }
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= nf; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d ", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    return 0;
}


WorstFit
#include <stdio.h>
#define max 25
int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, largest;
    static int bf[max], ff[max];
    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nf; i++) {
        largest = -1;
        ff[i] = 0;
        frag[i] = 0;
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) {
                    if (largest == -1 || temp > largest) {
                        largest = temp;
                        ff[i] = j;
                        frag[i] = temp;
                    }
                }
            }
        }
        if (ff[i] != 0) {
            bf[ff[i]] = 1;
        }
    }
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= nf; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    return 0;
}


Bankers Algorithm
#include <stdio.h>
int main() {
    int avail[10], alloc[10][10], max[10][10], need[10][10], maxres[10];
    int finish[10], safeseq[10];
    int m, n, i, j, sum, ind = 0, executed_processes = 0;
    printf("\nEnter the number of processes and the number of resources: ");
    scanf("%d%d", &n, &m);
    printf("\nEnter maximum instances of resources: \n");
    for (j = 0; j < m; j++) {
        scanf("%d", &maxres[j]);
        avail[j] = maxres[j];
    }
    printf("\nEnter the Allocated Matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\nEnter the Max Matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\nThe Need Matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < m; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += alloc[i][j];
        }
        avail[j] -= sum;
    }
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    int flag = 1;
    while (executed_processes < n && flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canExecute = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canExecute = 0;
                        break;
                    }
                }
                if (canExecute) {
                    safeseq[ind++] = i;
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    executed_processes++;
                    flag = 1;
                }
            }
        }
    }
    if (executed_processes < n) {
        printf("\n System is in an unsafe state. Deadlock may occur.\n");
        return 0;
    }
    printf("\nFollowing is the SAFE Sequence:\n");
    for (i = 0; i < n - 1; i++) {
        printf(" P%d ->", safeseq[i]);
    }
    printf(" P%d\n", safeseq[n - 1]);
    return 0;
}