// Create a structure to specify data on students given below:
//  Roll number, Name, Department, Course, Year of joining
//  Assume that there are not more than 100 students in the college.
//  a.Write a function to print the names of all students who joined in a particular year.
//  b.Write a function to print the data of a student whose roll number is given.

#include <stdio.h>
struct student
{
    int rollno;
    char name[20];
    char dept[20];
    char course[20];
    int year;
};
void print_year(struct student s[], int n, int year)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].year == year)
            printf("%s\n", s[i].name);
    }
}
void print_rollno(struct student s[], int n, int rollno)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].rollno == rollno)
            printf("%s\n", s[i].name);
    }
}
int main()
{
    int n, i, year, rollno;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student s[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the details of student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &s[i].rollno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Department: ");
        scanf("%s", s[i].dept);
        printf("Course: ");
        scanf("%s", s[i].course);
        printf("Year of joining: ");
        scanf("%d", &s[i].year);
    }
    printf("Enter the year: ");
    scanf("%d", &year);
    print_year(s, n, year);
    printf("Enter the roll number: ");
    scanf("%d", &rollno);
    print_rollno(s, n, rollno);

    return 0;
}
