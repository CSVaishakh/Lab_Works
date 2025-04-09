#include <stdio.h>

int main() {
    int rs[50], i, j, k, pageCount, frameCount, frames[20], freq[20], min, pageFaults = 0, found;

    printf("Enter number of page references: ");
    scanf("%d", &pageCount);

    printf("Enter the page references: ");
    for (i = 0; i < pageCount; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    // Initialize frames and their frequencies
    for (i = 0; i < frameCount; i++) {
        frames[i] = -1;
        freq[i] = 0;
    }

    printf("\nLFU Page Replacement:\n");

    for (i = 0; i < pageCount; i++) {
        found = 0;

        // Check if the page is already in a frame
        for (j = 0; j < frameCount; j++) {
            if (frames[j] == rs[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            // Look for an empty frame
            for (j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    frames[j] = rs[i];
                    freq[j] = 1;
                    pageFaults++;
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            // Find the least frequently used frame
            min = 0;
            for (k = 1; k < frameCount; k++) {
                if (freq[k] < freq[min]) {
                    min = k;
                }
            }
            frames[min] = rs[i];
            freq[min] = 1;
            pageFaults++;
        }

        // Display current frame status
        printf("\n");
        for (j = 0; j < frameCount; j++) {
            printf("\t%d", frames[j]);
        }
        if (!found) {
            printf("\tPF No. %d", pageFaults);
        }
    }

    printf("\n\nTotal number of page faults: %d\n", pageFaults);
    return 0;
}
