#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    FILE *f = fopen("Input100k.txt", "w"); // mo file va ghi du lieu vao file
    if(f == NULL){
        return 1;
    }

    int n = 100000;
    fprintf(f, "Input 100000 intervals\n");

    srand(time(NULL)); // giup tao thoi gian ngau nhien khac nhau cho moi lan chay ma -> giup khong bi trung lap
    for(int i = 0; i < n; i++){
        int start = rand() % 1000000;
        int duration = rand() % 1000 + 1;
        int finish = start + duration;

        fprintf(f, "%d %d \n", start, finish);  
    }
    fclose(f);
    return 0;
}
