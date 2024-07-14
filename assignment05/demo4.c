//Write a structure to store school student information. The student result is one of the members
//of this information. Note that till 4th standard school follows grade scheme (A / B / C) and after 
//4th standard it follows percentage pattern. Accept the information of 3 students from the user 
//and display it again


#include <stdio.h>

// Define the structure to store student information
struct Student {
    int rollNumber;
    char name[50];
    int standard;
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

    printf("Enter standard: ");
    scanf("%d", &student->standard);

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
    printf("Standard: %d\n", student.standard);

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













