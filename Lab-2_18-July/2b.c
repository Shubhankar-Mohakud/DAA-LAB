#include<stdio.h>
#include<stdlib.h>

FILE *fr, *fw;

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int min(int a, int b){
    if(a>b) return b;
    else return a;
}

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;

    return gcd(max(a,b)-min(a,b), min(a,b));
}

int main(int argc, char *argv[]){
    fr = fopen(argv[1], "r");
    fw = fopen(argv[2], "w");
    int size; 
    fscanf(fr, "%d", &size);
    int arr[2*size];
    for(int i=0; i<2*size; i=i+2){
        fscanf(fr, "%d", &arr[i]);
        fscanf(fr, "%d", &arr[i+1]);
    }
    for(int i=0; i<2*size; i=i+2){
        fprintf(fw, "GCD(%d, %d) = ", arr[i], arr[i+1]);
        int ans = gcd(arr[i], arr[i+1]);
        fprintf(fw, "%d", ans);
        fprintf(fw, "\n");
    }
    fclose(fr);
    fclose(fw);
    return 0;
}