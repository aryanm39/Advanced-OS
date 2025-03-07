/*Write a c program command line
you have to read every 100th character from file*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    FILE *file;
    char ch;
    int position = 99;
    if(argc!=2){
        printf("Provide all arguments");
        return -1;
    }
    /* if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    } */
    file = fopen(argv[1],"r");
    if(file==NULL){
        printf("Error while opening file");
        return -1;
    }
    printf("Reading every 100th char:");
    while(fseek(file,position,SEEK_SET)==0 && (ch=fgetc(file))!=EOF){
        printf("%c",ch);
        position+=100;
    }
    printf("\n");
    fclose(file);
    return 0;
}


    

