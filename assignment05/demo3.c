//Write a function to accept array of student’s information from the user. Write another function 
//to print the array student’s information.


#include <stdio.h>
struct student{
    int rollno;
    char name[50];
    float mark;

};
void acceptstudentinfo(struct student students[], int count);
void printfstudentinfo(struct student students[],int count);

int main(void)
{
    int count;
    printf("enter the no of student");
    scanf("%d",count);
    struct student students[count];
    acceptstudentinfo(students,count);
    printfstudentinfo(students,count);

    return 0;
}
void acceptstudentinfo(struct student students[], int count)
{
    int i;
    for(i=0;i<=count; i++)
    {
        printf("enter the details for student %d",i+1);
        printf("enter the rollno\n");
        scanf("rollno=%d",&students[i].rollno);
        printf("enter the name of the student\n");
        scanf("name=%s",students[i].name);
        printf("enter the mark of student of student");
        scanf("mark=%.2f",&students[i].mark);

    }
}
void printfstudentinfo(struct student students[],int count)
{
    int i;
    printf("student information\n");
    for(i=0; i<=count ; i++)
    {
        printf("student =%d",i+1);
        printf("rollno=%d",students[i].rollno);
        printf("name=%s",students[i].name);
        printf("mark=%.2f",students[i].mark);
    }
}
