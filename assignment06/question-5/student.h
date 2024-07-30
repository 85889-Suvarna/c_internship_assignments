// student.h
#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} student_t;

void write_student_to_file(FILE *file, const student_t *student);
void read_student_from_file(FILE *file, student_t *student);

#endif // STUDENT_H
