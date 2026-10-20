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
    if (fscanf(file, "%d", &total_tests) != 1) {
        printf("Error: Invalid file format in %s\n", filename);
        fclose(file);
        return;
    }

    printf("\nRUNNING VERIFICATION: %s \n", filename);
    int passed = 0;

    for (int t = 1; t <= total_tests; t++) {
        int n = 0;
        fscanf(file, "%d", &n);

        Activity *arr = NULL;
        if (n > 0) {
            arr = (Activity *)malloc(n * sizeof(Activity));
            for (int i = 0; i < n; i++) {
                fscanf(file, "%d %d", &arr[i].start, &arr[i].finish);
            }
        }

        /* Gọi hàm từ GreedyAlgorithm.h và BruteForce.h */
        int greedy_res = ActivitySelection(arr, n);
        int bf_res = BruteForceActivitySelection(arr, n);

        if (greedy_res == bf_res) {
            printf("[Test %02d] PASS | N = %2d | Greedy: %d | BruteForce: %d\n", t, n, greedy_res, bf_res);
            passed++;
        } else {
            printf("[Test %02d] FAIL | N = %2d | Greedy: %d | BruteForce: %d (MISMATCH!)\n", t, n, greedy_res, bf_res);
        }

        if (arr) free(arr);
    }
    printf("VERIFICATION SUMMARY: %d/%d tests passed (%.1f%%)\n", passed, total_tests, (float)passed / total_tests * 100);

    fclose(file);
}

int main() {
    ExecuteTestSuite("Test/EdgeCase.txt");
    ExecuteTestSuite("Test/TestCase.txt");
    return 0;
}