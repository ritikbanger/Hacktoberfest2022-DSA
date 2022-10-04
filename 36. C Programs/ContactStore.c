// Write a program to create a Telephone Directory
//  application, which will have options for
//  a.Add Contact (Name and Telephone No.)
//  b.Delete Contact
//  c.Search (By Name)
//  d.Browse (All Contacts)
//  Contact Information should be stored in a text file in
//  a readable format. Allow multiple telephone numbers
//  against a single contact name. [OPTIONAL]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct contact
{
    char name[20];
    char telephone[20];
};
void add_contact()
{
    FILE *fp;
    fp = fopen("telephone.txt", "a");

    struct contact c;
    printf("Enter the name: ");
    scanf("%s", c.name);
    printf("Enter the telephone number: ");
    scanf("%s", c.telephone);
    fprintf(fp, "%s %s\n", c.name, c.telephone);
    fclose(fp);
}
void delete_contact()
{
    FILE *fp;
    fp = fopen("telephone.txt", "r");

    struct contact c;
    printf("Enter the name: ");
    scanf("%s", c.name);
    while (fscanf(fp, "%s %s", c.name, c.telephone) != EOF)
    {
        if (strcmp(c.name, c.name) == 0)
        {
            fclose(fp);
            fp = fopen("telephone.txt", "w");
            continue;
        }
        fprintf(fp, "%s %s\n", c.name, c.telephone);
    }
    fclose(fp);
}
void search_contact()
{
    FILE *fp;
    fp = fopen("telephone.txt", "r");

    struct contact c;
    printf("Enter the name: ");
    scanf("%s", c.name);
    while (fscanf(fp, "%s %s", c.name, c.telephone) != EOF)
    {
        if (strcmp(c.name, c.name) == 0)
        {
            printf("%s %s\n", c.name, c.telephone);
            break;
        }
    }
    fclose(fp);
}

void browse_contact()
{
    FILE *fp;
    fp = fopen("telephone.txt", "r");
    struct contact c;
    while (fscanf(fp, "%s %s", c.name, c.telephone) != EOF)
    {
        printf("%s %s\n", c.name, c.telephone);
    }
    fclose(fp);
}
int main()
{
    int choice;
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Browse Contact\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_contact();
        break;
    case 2:
        delete_contact();
        break;
    case 3:
        search_contact();
        break;
    case 4:
        browse_contact();
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    return 0;
}