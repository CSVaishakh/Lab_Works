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
