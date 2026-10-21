#include <stdio.h>
#include <stdlib.h>

#include "../GreedyAlgorithm.h"
#include "../BruteForce.h"

void ExecuteTestSuite(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    int total_tests = 0;
    if (fscanf(file, "%d", &total_tests) != 1 || total_tests <= 0) {
        printf("Error: Invalid or zero test count in %s\n", filename);
        fclose(file);
        return;
    }

    printf("\nRUNNING VERIFICATION: %s \n", filename);
    int passed = 0;

    for (int t = 1; t <= total_tests; t++) {
        int n = 0;
        // VÁ LỖI 1: Kiểm tra việc đọc N
        if (fscanf(file, "%d", &n) != 1) {
            printf("Error: Failed to read N at test %d\n", t);
            break; 
        }

        Activity *arr = NULL;
        if (n > 0) {
            arr = (Activity *)malloc(n * sizeof(Activity));
            if (arr == NULL) {
                printf("Error: Memory allocation failed for N = %d\n", n);
                break;
            }
            
            for (int i = 0; i < n; i++) {
                if (fscanf(file, "%d %d", &arr[i].start, &arr[i].finish) != 2) {
                    printf("Error: Invalid activity data at test %d\n", t);
                    free(arr);
                    fclose(file);
                    return;
                }
            }
        }

        int greedy_res = ActivitySelection(arr, n);
        int bf_res = BruteForceActivitySelection(arr, n);

        if (greedy_res == bf_res && greedy_res != -1) {
            printf("[Test %02d] PASS | N = %2d | Greedy: %d | BruteForce: %d\n", t, n, greedy_res, bf_res);
            passed++;
        } else {
            printf("[Test %02d] FAIL | N = %2d | Greedy: %d | BruteForce: %d (MISMATCH/ERROR!)\n", t, n, greedy_res, bf_res);
        }

        if (arr) free(arr);
    }

    if (total_tests > 0) {
        printf("VERIFICATION SUMMARY: %d/%d tests passed (%.1f%%)\n", passed, total_tests, (float)passed / total_tests * 100);
    }

    fclose(file);
}

int main() {
    ExecuteTestSuite("Test/EdgeCase.txt");
    ExecuteTestSuite("Test/TestCase.txt");
    return 0;
}