#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

int CompareActivity(const void *a, const void *b) {
    Activity *actA = (Activity *)a;
    Activity *actB = (Activity *)b;
    if (actA->finish != actB->finish) {
        return actA->finish - actB->finish;
    }
    return actA->start - actB->start;
}

int SolveGreedy(Activity arr[], int n) {
    if (n <= 0) return 0;

    Activity *temp = (Activity *)malloc(n * sizeof(Activity));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    qsort(temp, n, sizeof(Activity), CompareActivity);

    int count = 1;
    int lastFinish = temp[0].finish;

    for (int i = 1; i < n; i++) {
        if (temp[i].start >= lastFinish) {
            count++;
            lastFinish = temp[i].finish;
        }
    }

    free(temp);
    return count;
}

int SolveBruteForce(Activity arr[], int n) {
    if (n <= 0) return 0;
    if (n > 30) return -1;

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
    return max_count;
}

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

    printf("\n============== RUNNING VERIFICATION: %s ==============\n", filename);
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

        int greedy_res = SolveGreedy(arr, n);
        int bf_res = SolveBruteForce(arr, n);

        if (greedy_res == bf_res) {
            printf("[Test %02d] PASS | N = %2d | Greedy: %d | BruteForce: %d\n", t, n, greedy_res, bf_res);
            passed++;
        } else {
            printf("[Test %02d] FAIL | N = %2d | Greedy: %d | BruteForce: %d (MISMATCH!)\n", t, n, greedy_res, bf_res);
        }

        if (arr) free(arr);
    }

    printf("----------------------------------------------------------\n");
    printf("VERIFICATION SUMMARY: %d/%d tests passed (%.1f%%)\n", passed, total_tests, (float)passed / total_tests * 100);
    printf("==========================================================\n");

    fclose(file);
}

int main() {
    ExecuteTestSuite("Test/EdgeCase.txt");
    ExecuteTestSuite("Test/TestCase.txt");
    return 0;
}