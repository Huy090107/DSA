#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start;
    int finish;
} Activity;
int Compare(const void *a, const void *b){
    Activity *activityA = (Activity *)a; 
    Activity *activityB = (Activity *)b;
    if(activityA->finish < activityB->finish) return -1;
    else if(activityA->finish > activityB->finish) return 1;
    else return 0;
}

void ActivitySelection(Activity arr[], int n){

    if(n == 0){
        printf("No activities to select. \n");
        return;
    }

    int count = 1 ;

    qsort(arr, n, sizeof(Activity), Compare);
    
    int FinishTime = arr[0].finish;

    for(int i = 1; i < n; i++){
        if(FinishTime <= arr[i].start){
            FinishTime = arr[i].finish;
            count++;
        }
    }
    printf("Maximum number of activities that can be selected: %d\n", count);
}

int main(){
    Activity arr[] = {{1, 4}, {4, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    ActivitySelection(arr, n);
    return 0;
}
