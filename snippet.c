#include<stdio.h>

FILE *fr, *fw;

void close_File_IO(){
    fclose(fr);
    fclose(fw);
    return;
}

int main(int argc, char *argv[]){
    fr = fopen(argv[1], "r");
    if (fr == NULL) {
        printf("Error\n");
        exit(1);
    }
    fw = fopen(argv[2], "w");

    return 0;
}