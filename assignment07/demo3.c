//Write a C program that takes two command line arguments: the source file and the
//destination file. The program should copy the contents of the source file to the 
//destination file. If the number of arguments is not exactly two, or if the source 
//file cannot be opened, print an error message.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is exactly two
    if (argc != 3) {
        fprintf(stderr, "Error: Exactly two arguments are required (source file and destination file).\n");
        return 1;
    }

    // Open the source file for reading
    FILE *sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL) {
        fprintf(stderr, "Error: Could not open source file %s for reading.\n", argv[1]);
        return 1;
    }

    // Open the destination file for writing
    FILE *destFile = fopen(argv[2], "w");
    if (destFile == NULL) {
        fprintf(stderr, "Error: Could not open destination file %s for writing.\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents from source file to destination file
    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destFile);

    printf("File copied successfully from %s to %s.\n", argv[1], argv[2]);

    return 0;
}
