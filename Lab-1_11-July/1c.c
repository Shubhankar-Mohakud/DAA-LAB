#include<stdio.h>
#include<limits.h>

int main(){
    FILE *fr, *fw;
    int rep[11];
    int arr[11];
    for(int i=0; i<11; i++){
        arr[i]=0;
    }
    // reading inputs from src-1c.txt
    fr = fopen("src-1c.txt", "r");
    for(int i=0; i<10; i++){
        fscanf(fr, "%d", &rep[i]);
    }
    for(int i=0; i<10; i++){
        arr[rep[i]]++;
    }
    // 
    fw = fopen("ans-1c.txt", "w");
    fprintf(fw, "Repeated Elements\n");
    int mostRep = 0;
    for(int i=0; i<11; i++){
        if(arr[i]>1) fprintf(fw, "%d : %d\n", i, arr[i]);
        if(arr[i]>arr[mostRep]) mostRep = i;
    }
    fprintf(fw, "Most repeated element : %d -> %d", mostRep, arr[mostRep]);
    fclose(fr);
    fclose(fw);

    return 0;
}