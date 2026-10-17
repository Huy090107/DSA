#include <stdio.h>
#include <stdlib.h>
#include "StructActivity.h"


//Sap xep tang dan theo thoi gian ket thuc cua cac hoat dong
int Compare(const void *a, const void *b){
    Activity *activityA = (Activity *)a; 
    Activity *activityB = (Activity *)b;
    if(activityA->finish < activityB->finish) return -1;
    else if(activityA->finish > activityB->finish) return 1;
    else return 0;
}

//Thuat toan tham lam de chon cac hoat dong
void ActivitySelection(Activity arr[], int n){

    if(n == 0){
        printf("No activities to select. \n");
        return;
    }

    int count = 1 ;

    //Sap xep cac hoat dong theo thoi gian ket thuc tang dan bang qsort
    qsort(arr, n, sizeof(Activity), Compare);
    
    int FinishTime = arr[0].finish;

    //Duyet va chon hoat dong 
    for(int i = 1; i < n; i++){
        if(FinishTime <= arr[i].start){
            FinishTime = arr[i].finish;
            count++;
        }
    }
    printf("Maximum number of activities that can be selected: %d\n", count);
}

