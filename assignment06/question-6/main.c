#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "student_database.bin"

typedef struct {
    int roll_number;
    char name[50];
    int age;
    char course[50];
} Student;

typedef enum {
    ADD_RECORD = 1,
    READ_RECORD,
    SEARCH_BY_ROLL,
    SEARCH_BY_NAME,
    MODIFY_RECORD,
    REMOVE_RECORD,
    EXIT_PROGRAM
} MenuOptions;

void addRecord();
void readRecords();
void searchByRollNumber();
void searchByName();
void modifyRecord();
void removeRecord();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case ADD_RECORD:
                addRecord();
                break;
            case READ_RECORD:
                readRecords();
                break;
            case SEARCH_BY_ROLL:
                searchByRollNumber();
                break;
            case SEARCH_BY_NAME:
                searchByName();
                break;
            case MODIFY_RECORD:
                modifyRecord();
                break;
            case REMOVE_RECORD:
                removeRecord();
                break;
            case EXIT_PROGRAM:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nStudent Database Menu:\n");
    printf("1. Add Student Record\n");
    printf("2. Read All Student Records\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Search Student by Name\n");
    printf("5. Modify Student Record\n");
    printf("6. Remove Student Record\n");
    printf("7. Exit\n");
}

void addRecord() {
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    Student student;
    printf("Enter roll number: ");
    scanf("%d", &student.roll_number);
    printf("Enter name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter age: ");
    scanf("%d", &student.age);
    printf("Enter course: ");
    scanf(" %[^\n]", student.course);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student record added successfully.\n");
}

void readRecords() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    Student student;
    printf("\nStudent Records:\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("Roll Number: %d\n", student.roll_number);
        printf("Name: %s\n", student.name);
        printf("Age: %d\n", student.age);
        printf("Course: %s\n", student.course);
        printf("------------------------\n");
    }
    fclose(file);
}

void searchByRollNumber() {
    int roll_number;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_number);

    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.roll_number == roll_number) {
            printf("Record Found:\n");
            printf("Roll Number: %d\n", student.roll_number);
            printf("Name: %s\n", student.name);
            printf("Age: %d\n", student.age);
            printf("Course: %s\n", student.course);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
    fclose(file);
}

void searchByName() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (strcmp(student.name, name) == 0) {
            printf("Record Found:\n");
            printf("Roll Number: %d\n", student.roll_number);
            printf("Name: %s\n", student.name);
            printf("Age: %d\n", student.age);
            printf("Course: %s\n", student.course);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
    fclose(file);
}

void modifyRecord() {
    int roll_number;
    printf("Enter roll number to modify: ");
    scanf("%d", &roll_number);

    FILE *file = fopen(FILENAME, "rb+");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    Student student;
    int found = 0;
    long pos;
    while ((pos = ftell(file)) != -1 && fread(&student, sizeof(Student), 1, file)) {
        if (student.roll_number == roll_number) {
            printf("Record Found. Enter new details.\n");
            printf("Enter new name: ");
            scanf(" %[^\n]", student.name);
            printf("Enter new age: ");
            scanf("%d", &student.age);
            printf("Enter new course: ");
            scanf(" %[^\n]", student.course);

            fseek(file, pos, SEEK_SET);
            fwrite(&student, sizeof(Student), 1, file);
            found = 1;
            printf("Record modified successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
    fclose(file);
}

void removeRecord() {
    int roll_number;
    printf("Enter roll number to remove: ");
    scanf("%d", &roll_number);

    FILE *file = fopen(FILENAME, "rb");
    FILE *temp = fopen("temp.bin", "wb");
    if (!file || !temp) {
        printf("Unable to open file.\n");
        return;
    }

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.roll_number == roll_number) {
            found = 1;
        } else {
            fwrite(&student, sizeof(Student), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename("temp.bin", FILENAME);

    if (found) {
        printf("Record removed successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}
