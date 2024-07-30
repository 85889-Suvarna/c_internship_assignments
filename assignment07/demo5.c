//Write a C program that takes a directory path and a file name as command line 
//arguments. The program should check if the file exists in the specified directory 
//and print a message indicating whether the file was found or not
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is exactly two
    if (argc != 3) {
        fprintf(stderr, "Error: Exactly two arguments are required (directory path and file name).\n");
        return 1;
    }

    // Get the directory path and file name from the arguments
    char *dirPath = argv[1];
    char *fileName = argv[2];

    // Open the directory
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        fprintf(stderr, "Error: Could not open directory %s.\n", dirPath);
        return 1;
    }

    // Read the directory contents
    struct dirent *entry;
    int fileFound = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, fileName) == 0) {
            fileFound = 1;
            break;
        }
    }

    // Close the directory
    closedir(dir);

    // Print whether the file was found or not
    if (fileFound) {
        printf("File %s found in directory %s.\n", fileName, dirPath);
    } else {
        printf("File %s not found in directory %s.\n", fileName, dirPath);
    }

    return 0;
}
