//Write a C program that takes multiple filenames as command line arguments and 
//merges their contents into a single file named "merged.txt". If no files are 
//provided or if any file cannot be opened, print an appropriate error message. Ensure
//that the contents are merged in the order of the filenames provided.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if at least one filename is provided
    if (argc < 2) {
        fprintf(stderr, "Error: At least one filename must be provided.\n");
        return 1;
    }

    // Open the output file for writing
    FILE *outputFile = fopen("merged.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not open output file merged.txt for writing.\n");
        return 1;
    }

    // Loop through each input file
    for (int i = 1; i < argc; i++) {
        FILE *inputFile = fopen(argv[i], "r");
        if (inputFile == NULL) {
            fprintf(stderr, "Error: Could not open input file %s for reading.\n", argv[i]);
            fclose(outputFile);
            return 1;
        }

        // Copy contents from the input file to the output file
        char ch;
        while ((ch = fgetc(inputFile)) != EOF) {
            fputc(ch, outputFile);
        }

        fclose(inputFile);
    }

    fclose(outputFile);
    printf("Files merged successfully into merged.txt.\n");

    return 0;
}
