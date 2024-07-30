// main.c
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    const char *filename = "students.txt";
    FILE *file;

    // Writing student records to file
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return 1;
    }

    student_t students_to_write[] = {
        {1, "Alice", 20, 3.8},
        {2, "Bob", 21, 3.5},
        {3, "Charlie", 19, 3.9}
    };

    for (int i = 0; i < sizeof(students_to_write) / sizeof(student_t); i++) {
        write_student_to_file(file, &students_to_write[i]);
    }

    fclose(file);

    // Reading student records from file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return 1;
    }

    student_t student;
    while (fscanf(file, "%d %s %d %f", &student.id, student.name, &student.age, &student.gpa) != EOF) {
        printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", student.id, student.name, student.age, student.gpa);
    }

    fclose(file);

    return 0;
}