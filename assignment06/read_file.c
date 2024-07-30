//. Write a program to read a file character by character and display its content on screen
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *file;
    char filename[100];
    char ch;

    printf("enter the file name top open:");
    scanf("%s",filename);

    file = fopen(filename ,"r");
    if(file == NULL){
        perror("Error opening file");
        return 1;
    }
    //read the file character by character and display on screen
    while((ch=fgetc(file))!=EOF)
    {
        putchar(ch);
    }

    fclose(file);
    return 0;
}