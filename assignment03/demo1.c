
//Declare an integer variable x and initialize it to 25. Declare a
//pointer to an integer and initialize it to point to x. Print the value of x
//using the pointer.
#include <stdio.h>

int main() {
    int x = 25;        // Declare and initialize x
    int *ptr = &x;     // Declare a pointer to an integer and initialize it to point to x


    printf("The value of x is: %d\n", *ptr);

    return 0;
}
