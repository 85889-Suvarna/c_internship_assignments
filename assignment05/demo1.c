//Declare a structure to store data for student information. The structure contains roll number, 
//name, marks for students

#include <stdio.h>
struct student{
    int rollnumber;
    char name[20];
    float mark;

};
void acceptstudentinfo(struct student *student);
void printstudentinfo(struct student student);

int main(void)
{
    struct student student;
    acceptstudentinfo(&student);
    printstudentinfo(student);
    return 0;
}
void acceptstudentinfo(struct student *student)
{
    printf("enter the student info");
    printf("enter the student rollno\n");
    scanf("%d",&student->rollnumber);
    printf("enter the student name\n");
    scanf("%s",student->name);
    printf("enter the student mark\n");
    scanf("%.2f",&student->mark);
}

void printstudentinfo(struct student student)
{
    printf("the student information is");
    printf("rollno=%d",student.rollnumber);
    printf("student name =%s",student.name);
    printf("student mark =%f", student.mark);
}