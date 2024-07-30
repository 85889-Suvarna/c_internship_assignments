//Write a function to read a file line by line and copy the contents to another file
#include<stdio.h>
#include <stdlib.h>
 # define MAX_LINE_LEN 1024

 void copy_file_line_by_line(FILE *src ,FILE *dest){
     char line[MAX_LINE_LEN];
     while(fgets(line,sizeof(line),src)!=NULL){
         fputs(line,dest);

     }
 }

 int main(void)
 {
     FILE *src_file, *dest_file;
     char src_filename[100],dest_filename[100];
     printf("enter the source filename to open");
     scanf("%s",src_filename);

     src_file= fopen(src_filename,"r");
     if(src_file == NULL){
         perror("error opening of the source file");
         return 1;
     }

     printf(" enter the file name to open the destination file\n");
     scanf("%s",dest_filename);

    dest_file= fopen(dest_filename ,"w");
    if(dest_file ==NULL){
        perror("error opening the destination file");
        return 1;

    }
    copy_file_line_by_line(src_file,dest_file);
    fclose(src_file);
    fclose(dest_file);

    //open the destination file in the read mode to display the contents

    dest_file= fopen(dest_filename,"r");
    if(dest_file==NULL){
        perror("error opening the destination file");
        return 1;

    }
    printf("the contents of the destination file is\n");
    char ch;
    while((ch=fgetc(dest_file))!=EOF){
        fputchar(ch);
    }
    fclose(dest_file);
    //accept the addtional data from user write them into the destination file
    dest_file = fopen(dest_filename,"a");
    if(dest_file == NULL){
        perror("erroe for opening the destination file");
        return 1;

    }
    printf("enter data to append in destination file");
    getchar();
    while((ch=getchar())!=EOF){
        fputc(ch,dest_file);

    }
    fclose(dest_file);
    return 0;
 }
 