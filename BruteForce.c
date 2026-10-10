#include <stdio.h>
#include "StructActivity.h"

void BruteForceActivitySelection(Activity arr[], int n) {
    if (n == 0) {
        printf("No activities to select.\n");
        return;
    }

    if (n > 30) {
        printf("N is too large for Brute Force (Max N = 30).\n");
        return;
    }

    int max_count = 0;
    unsigned long long total_subsets = 1ULL << n; 

    for (unsigned long long mask = 0; mask < total_subsets; mask++) {
        int current_count = 0;
        int is_valid = 1;

        for (int i = 0; i < n; i++) {
            if (mask & (1ULL << i)) {
                current_count++;
            }
        }

        if (current_count > max_count) {
            for (int i = 0; i < n; i++) {
                if (mask & (1ULL << i)) {
                    for (int j = i + 1; j < n; j++) {
                        if (mask & (1ULL << j)) {
                            if (arr[i].start < arr[j].finish && arr[j].start < arr[i].finish) {
                                is_valid = 0;
                                break;
                            }
                        }
                    }
                }
                if (!is_valid) break;
            }

            if (is_valid) {
                max_count = current_count;
            }
        }
    }

    printf("[Brute Force] Maximum number of activities that can be selected: %d\n", max_count);
}

