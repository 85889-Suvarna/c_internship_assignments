//Write a C program that takes in two integer command line arguments and prints 
//their sum. If the number of arguments is not exactly two, print an error message
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is exactly two
    if (argc != 3) {
        fprintf(stderr, "Error: Exactly two integer arguments are required.\n");
        return 1;
    }

    // Convert the arguments from strings to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // Calculate the sum
    int sum = num1 + num2;

    // Print the sum
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    return 0;
}
