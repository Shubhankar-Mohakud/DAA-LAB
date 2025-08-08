#include<stdio.h>
#include<stdlib.h>

FILE *fr, *fw;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return; 
    
    int pivot = arr[high];
    int i = low;  
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;  
        }
    }
    swap(&arr[i], &arr[high]);
    
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

void close_File_IO(){
    fclose(fr);
    fclose(fw);
    return;
}

int main(int argc, char *argv[]){
    fr = fopen(argv[1], "r");
    if (fr == NULL) {
        printf("Error\n");
        // exit(1);
    }
    fw = fopen(argv[2], "w");
    int arr[300];
    /*
    -----RANDOM NUMBERS------

    for(int i=0; i<300; i++){
        int num = rand();
        fprintf(fr, "%d ", num);
    }
    */
    for(int i=0; i<300; i++){
        fscanf(fr, "%d",&arr[i]);
    }

    fprintf(fw, "UNSORTED ARRAY\n");
    for(int i=1; i<=300; i++){
        fprintf(fw, "%d ", arr[i-1]);
        if(i%10==0) fprintf(fw, "\n");
    }
    
    quickSort(arr,0,299);
    fprintf(fw, "\nSORTED ARRAY\n");
    for(int i=1; i<=300; i++){
        fprintf(fw, "%d ", arr[i-1]);
        if(i%10==0) fprintf(fw, "\n");
    }
    close_File_IO();
    return 0;
}