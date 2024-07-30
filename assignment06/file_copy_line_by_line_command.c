#include<stdio.h>
#include<stdlib.h>

# define MAX_LINE_LEN 1024

void copy_file_line_by_line(FILE *src, FILE *dest){
    char line[MAX_LINE_LEN];
    while(fgets(line,sizeof(line),src)!=NULL){
        fputs(line,dest);
    }
}
int main(int argc ,char *argv[]){

    if(argc!=3){
        fprintf(stderr,"%s<source filenmae><destination filename>\n",argv[0]);
        return 1;

    }
    char *src_filename=argv[1];
    char *dest_filename=argv[2];

    FILE *src_file=fopen(src_filename,"r");
    if(src_file==NULL){
        perror("error opening the source file\n");
        return 1;

    }

    FILE *dest_file= fopen(dest_filename,"w");
    if(dest_file==NULL){
        perror("error opening the destination file\n");
        return 1;

    }
    copy_file_line_by_line(src_file,dest_file);
    fclose(src_file);
    fclose(dest_file);

    //open destination file to read and display the content
    dest_file=fopen(dest_filename,"r");
    if(dest_file==NULL){
        perror("error of opening the destination file\n");
        return 1;
    }
    printf("content of the destination file is");
    char ch;
    while((ch=fgetc(dest_file))!=EOF){
        putchar(ch);

    }
    fclose(dest_file);

    //accept the addtional data from the user and write to the destination
    dest_file=fopen(dest_filename,"a");
    if(dest_file==NULL){
        perror("error to open destination file");
        return 1;

    }
    printf("\n enter data to append to the destination file(end with EOF)\n");
    getchar();//printf the next input of the perivious input
    while((ch=getchar())!=EOF){
        fputc(ch,dest_file);
    }
    fclose(dest_file);
    return 0;
}