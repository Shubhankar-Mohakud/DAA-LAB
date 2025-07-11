#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fr, *fw;
    int arr[5];
    int ans[5];
    int sum = 0;
    // read inputs from src-1b.txt
    fr = fopen("src-1b.txt", "r");
    for(int i=0; i<5; i++){
        fscanf(fr, "%d", &arr[i]);
    }
    // main logic
    for(int i=0; i<5; i++){
        sum += arr[i];
        ans[i]=sum;
    }
    // write outputs in ans-1b.txt
    fw = fopen("ans-1b.txt", "w");
    for(int i=0; i<5; i++){
        fprintf(fw, "%d ", ans[i]);
    }
    fclose(fr);
    fclose(fw);
    return 0;
}