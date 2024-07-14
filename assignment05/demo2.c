//Write a function to accept student information from the user. Write another function to print
//student’s information


#include <stdio.h>

struct Student {
    int rollNumber;
    char name[50];
    float marks;
};


void acceptStudentInfo(struct Student *student) {
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter name: ");
    scanf("%s", student->name);

    printf("Enter marks: ");
    scanf("%f", &student->marks);
}

void printStudentInfo(struct Student student) {
    printf("\nStudent Information:\n");
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);
}

int main() {
    struct Student student;

    acceptStudentInfo(&student);


    printStudentInfo(student);

    return 0;
}
