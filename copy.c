/*Write a program to copy one file to another using command*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    FILE *source,*Dest;
    char ch;
    if(argc!=3){
        printf("Provide all three arguments");
        return -1;
    }
    source = fopen(argv[1],"r");
    if(source==NULL){
        printf("Error while opening the file");
        return -1;
    }
    Dest = fopen(argv[2],"w");
    if(Dest == NULL){
        printf("Error while opening write file");
        return -1;
    }
    while((ch=fgetc(source))!=EOF){
        fputc(ch,Dest);
    }
    printf("File is copied");
    fclose(source);
    fclose(Dest);
    return 0;
}