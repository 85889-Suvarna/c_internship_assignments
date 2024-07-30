//Write a function to read a file character by character and copy the contents to another file. 
//Source file pointer and Destination file pointers should be arguments to the function. Use the 
//function to copy the file to destination file, display contents of the file, accept data from user 
//and write to destination file.
#include<stdio.h>
#include<stdlib.h>
void copy_file(FILE *src, FILE *dest) {
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
}


int main(){
    FILE *src_file, *dest_file;
    char src_filename[100],dest_filename[100];
    char ch;

    printf("enter the file name to open ");
    scanf("%s",src_filename);

    src_file = fopen(src_filename,"r");
    if(src_file== NULL){
        perror("Error opening source file");
        return 1;

    }
    printf("enter the destination filename to open:");
    scanf("%s",dest_filename);

    dest_file= fopen(dest_filename,"w");
    if(dest_file == NULL){
        perror("erroe opening destinstion file");
        fclose(src_file);
        return 1;
    }
    copy_file(src_file, dest_file);

    fclose(src_file);
    fclose(dest_file);

    //open the dest file in read mode to display its contents
    dest_file = fopen(dest_filename,"r");
    if(dest_file ==NULL){
        perror("error opening destinstion file");
        return 1;


    }

    printf("\n contents of the destination file:\n");
    while((ch=fgetc(dest_file))!=EOF){
        putchar(ch);
    }
    fclose(dest_file);
    //accept additional data from the user and write to the destination file
    dest_file= fopen(dest_filename,"a");
    if(dest_file == NULL){
        perror("error opening destination file");
        return 1;


    }
    printf("\n enter data to append to the destination file (end with EOF):\n");
    getchar();
    while((ch=getchar())!= EOF){
        fputc(ch,dest_file);

    }
    fclose(dest_file);
    return 0;
}