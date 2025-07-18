#include<stdio.h>
#include<stdlib.h>

FILE *fr, *fw;

void decToBin(int num){
    if(num==0){
        return;
    }
    int bit = num&1;
    decToBin(num>>1);
    fprintf(fw, "%d", bit);
}

int main(int argc, char *argv[]){
    
    fr = fopen(argv[1], "r");
    if (fr == NULL) {
        printf("Error ");
        exit(1);
    }
    fw = fopen(argv[2], "w");
    int size;
    fscanf(fr, "%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        fscanf(fr, "%d", &arr[i]);
    }

    for(int i=0; i<size; i++){
        fprintf(fw, "%d = ", arr[i]);
        decToBin(arr[i]);
        fprintf(fw, "\n");
    }
    fclose(fr);
    fclose(fw);
    return 0;
}