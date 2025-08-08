#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

FILE *fr, *fw;
long long count=0;

void close_File_IO(){
    fclose(fr);
    fclose(fw);
    return;
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++){
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        count++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        count++;
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        count++;
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(int argc, char *argv[]){
    fr = fopen(argv[1], "r");
    if (fr == NULL) {
        printf("Error\n");
        exit(1);
    }
    fw = fopen(argv[2], "w");
    int arr[300];
    /*
    -----FROM RANDOM NUMBER GENERATION-------

    for(int i=0; i<300; i++){
        int num = rand();
        fprintf(fr, "%d ", num);
    }
    */
    for(int i=0; i<300; i++){
        fscanf(fr, "%d",&arr[i]);
    }
    
    int size = sizeof(arr)/sizeof(arr[0]);
    clock_t start = clock();

    mergeSort(arr, 0, size - 1);

    clock_t end = clock();

    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    fprintf(fw, "Time Taken by Merge Sort : %f\n", seconds);
    fprintf(fw, "---RANDOM ORDER---\n");
    fprintf(fw, "Number of comparisions : %d\n", count);
    for(int i=1; i<=300; i++){
        fprintf(fw, "%d ", arr[i-1]);
        if(i%10==0) fprintf(fw, "\n");
    }
        
    close_File_IO();
    return 0;
}