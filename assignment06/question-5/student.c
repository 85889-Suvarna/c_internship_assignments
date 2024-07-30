// student.c
#include <stdio.h>
#include "student.h"

void write_student_to_file(FILE *file, const student_t *student) {
    if (file == NULL || student == NULL) {
        fprintf(stderr, "Invalid file pointer or student pointer\n");
        return;
    }
    fprintf(file, "%d %s %d %.2f\n", student->id, student->name, student->age, student->gpa);
}

void read_student_from_file(FILE *file, student_t *student) {
    if (file == NULL || student == NULL) {
        fprintf(stderr, "Invalid file pointer or student pointer\n");
        return;
    }
    fscanf(file, "%d %s %d %f", &student->id, student->name, &student->age, &student->gpa);
}
