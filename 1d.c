#include<stdio.h>
#include<stdlib.h>

void EXCHANGE(int *a,int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void ROTATE_RIGHT(int p1[], int p2){
    --p2;
    for(int i=p2; i>0; i--){
        EXCHANGE(&p1[i], &p1[i-1]);
    }
}

int main(){
    FILE *fr, *fw;
    int arr[9];
    int p2;
    fr = fopen("src-1d.txt", "r");
    fscanf(fr, "%d", &p2);
    for(int i=0; i<9; i++){
        fscanf(fr, "%d", &arr[i]);
    }
    fw = fopen("ans-1d.txt", "w");
    fprintf(fw, "Before Rotation\n");
    for(int i=0; i<9; i++){
        fprintf(fw, "%d ", arr[i]);
    }
    fprintf(fw, "\n\n");
    ROTATE_RIGHT(arr, p2);
    fprintf(fw, "After Rotation\n");
    for(int i=0; i<9; i++){
        fprintf(fw, "%d ", arr[i]);
    }
    fclose(fr);
    fclose(fw);
    return 0;
}