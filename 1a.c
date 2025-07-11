#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
    FILE *fp, *fw;
    fp = fopen("new.txt", "r");
    if (fp == NULL) {
        printf("Error ");
        exit(1);
    }
    int arr[5];
    for(int i=0; i<5; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    int smallest = INT_MAX;
    int largest = INT_MIN;
    
    for(int i=0; i<5; i++){
        if(arr[i]>largest) largest = arr[i];
        if(arr[i]<smallest) smallest = arr[i];
    }
    int secSmall = INT_MAX;
    int secLarge = INT_MIN;
    for(int i=0; i<5; i++){
        if(arr[i]>secLarge && arr[i]!=largest) secLarge = arr[i];
        if(arr[i]<secSmall && arr[i]!=smallest) secSmall = arr[i];
    }
    fw = fopen("ans.txt", "w");
    fprintf(fw, "Second Smallest : %d\n", secSmall);
    fprintf(fw, "Second Largest : %d\n", secLarge);
    fclose(fp);
    fclose(fw);
    return 0;
}