//Write a function void swap(int *a, int *b) that swaps the values of
//two integers. Demonstrate this function in main using two integer 
//variables.
#include <stdio.h>

// Function to swap the values of two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Before swap:\n");
    printf("x = %d, y = %d\n", x, y);

    // Call the swap function
    swap(&x, &y);

    printf("After swap:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
