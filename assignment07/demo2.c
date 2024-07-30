//Write a C program that takes in multiple integer command line arguments and 
//calculates their average. If no integers are provided, print an error message.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if at least one integer argument is provided
    if (argc < 2) {
        fprintf(stderr, "Error: At least one integer argument is required.\n");
        return 1;
    }

    // Variables to hold the sum of the integers and the count
    int sum = 0;
    int count = argc - 1;

    // Loop through the arguments and calculate the sum
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }

    // Calculate the average
    double average = (double)sum / count;

    // Print the average
    printf("The average of the provided integers is %.2f.\n", average);

    return 0;
}
