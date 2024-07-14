//Write a function to search student’s information by roll number. Write another function to 
//search student’s information by name

#include <stdio.h>
#include <string.h>

// Define the structure to store student information
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Function to accept an array of student information
void acceptStudentsInfo(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);
        
        printf("Enter name: ");
        scanf("%s", students[i].name);
        
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
        
        printf("\n");
    }
}

// Function to print an array of student information
void printStudentsInfo(struct Student students[], int count) {
    printf("\nStudents Information:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

// Function to search student information by roll number
void searchStudentByRollNumber(struct Student students[], int count, int rollNumber) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent with roll number %d not found.\n", rollNumber);
    }
}

// Function to search student information by name
void searchStudentByName(struct Student students[], int count, char name[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("\nStudent found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent with name %s not found.\n", name);
    }
}

int main() {
    int count;
    
    printf("Enter the number of students: ");
    scanf("%d", &count);

    struct Student students[count];

    // Accept array of student information
    acceptStudentsInfo(students, count);

    // Print array of student information
    printStudentsInfo(students, count);

    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);
    searchStudentByRollNumber(students, count, rollNumber);

    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    searchStudentByName(students, count, name);

    return 0;
}
