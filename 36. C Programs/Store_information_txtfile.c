// Write a program in C to create and store information in a text file.
#include <stdio.h>
struct contact
{
    char name[20];
    char telephone[20];
};
int main()
{
    FILE *fp;
    struct contact c;
    fp = fopen("input2.txt", "a");
    printf("Enter the name: ");
    scanf("%s", c.name);
    printf("Enter the telephone number: ");
    scanf("%s", c.telephone);
    fprintf(fp, "%s %s\n", c.name, c.telephone);
    fclose(fp);
    return 0;
}