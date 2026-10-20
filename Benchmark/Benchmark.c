#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GreedyAlgorithm.h"

int main(){

    FILE *file = fopen("Benchmark/Input100k.txt", "r");
    if(file == NULL){
        printf("Cannot open file");
        return 1;
    }

    //Doc phan tu dau file
    int n = 0;
    if(fscanf(file, "%d", &n) != 1 || n <= 0){
        printf("Error: Invalid data");
        fclose(file);
        return 1;
    }

    //Tao bo nho cho mang
    Activity *arr = (Activity*)malloc(n * sizeof(Activity));
    if(arr == NULL){
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }

    for(int i = 0; i < n; i++){
        fscanf(file, "%d %d", &arr[i].start, &arr[i].finish);
    }
    fclose(file);

    clock_t StartTime = clock();

    int result = ActivitySelection(arr, n);

    clock_t EndTime = clock();


    double Time = ((double)(EndTime - StartTime)) / CLOCKS_PER_SEC;

    printf("Max Activities: %d\n", result);
    printf("Algorithm runtime: %.3f ms\n", Time * 1000);
    
    free(arr);
    return 0;
}