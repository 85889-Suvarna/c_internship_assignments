//Write a structure to store school student information. Note that assuming the records are 
//maintained till 12th standard student, standard field do not occupy more than 4 bits. Also 
//student gender can be stored as a single bit. Consider age to be maximum 32 years. Accept the 
//information of 3 students from the user and display it again
#include <stdio.h>

// Define the structure to store student information using bit-fields
struct Student {
    int rollNumber;
    char name[50];
    unsigned int standard : 4;  // 4 bits for standard (0-15)
    unsigned int gender : 1;    // 1 bit for gender (0 for male, 1 for female)
    unsigned int age : 6;       // 6 bits for age (0-63)
    union {
        char grade;       // For students up to 4th standard
        float percentage; // For students above 4th standard
    } result;
};

// Function to accept student information
void acceptStudentInfo(struct Student *student) {
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter name: ");
    scanf("%s", student->name);

    printf("Enter standard (0-12): ");
    scanf("%u", &student->standard);

    printf("Enter gender (0 for male, 1 for female): ");
    scanf("%u", &student->gender);

    printf("Enter age (0-32): ");
    scanf("%u", &student->age);

    if (student->standard <= 4) {
        printf("Enter grade (A/B/C): ");
        scanf(" %c", &student->result.grade);
    } else {
        printf("Enter percentage: ");
        scanf("%f", &student->result.percentage);
    }
}

// Function to print student information
void printStudentInfo(struct Student student) {
    printf("\nStudent Information:\n");
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Name: %s\n", student.name);
    printf("Standard: %u\n", student.standard);
    printf("Gender: %s\n", student.gender == 0 ? "Male" : "Female");
    printf("Age: %u\n", student.age);

    if (student.standard <= 4) {
        printf("Grade: %c\n", student.result.grade);
    } else {
        printf("Percentage: %.2f\n", student.result.percentage);
    }
}

int main() {
    struct Student students[3];

    // Accept information for 3 students
    for (int i = 0; i < 3; i++) {
        printf("Enter details for student %d:\n", i + 1);
        acceptStudentInfo(&students[i]);
        printf("\n");
    }

    // Print information for 3 students
    for (int i = 0; i < 3; i++) {
        printStudentInfo(students[i]);
    }

    return 0;
}
