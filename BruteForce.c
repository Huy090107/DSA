#include <stdio.h>
#include "StructActivity.h"


void BruteForceActivitySelection(Activity arr[], int n) {
    if (n == 0) {
        printf("No activities to select.\n");
        return;
    }

    int max_count = 0;
    int total_subsets = 1 << n;

    for (int mask = 0; mask < total_subsets; mask++) {
        int current_count = 0;
        int is_valid = 1;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                current_count++;

                for (int j = i + 1; j < n; j++) {
                    if (mask & (1 << j)) {
                        if (arr[i].start < arr[j].finish && arr[j].start < arr[i].finish) {
                            is_valid = 0;
                            break;
                        }
                    }
                }
            }
            if (!is_valid) break;
        }

        if (is_valid && current_count > max_count) {
            max_count = current_count;
        }
    }

    printf("[Brute Force] Maximum number of activities that can be selected: %d\n", max_count);
}

