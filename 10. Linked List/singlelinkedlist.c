#include <stdio.h>
#include <stdlib.h>
// Linked List Node
struct node {
    int data;
    struct node* link;
};
struct node* head = NULL;
 
// Function to create list with n nodes initially
void createList()
{
    
            struct node* newnode, *temp;
            int data;
            newnode = malloc(sizeof(struct node));
            head = newnode;
            temp = head;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &data);
            newnode->data = data;
            if(head== NULL)
              {
                  newnode->link=NULL;
                  head=newnode;
              }
            else
             {
                  newnode->link=head;
                  head=newnode;
              }
}
 
// Function to traverse the linked list
void traverse()
{
    struct node* temp;
 
    // List is empty
    if (head == NULL)
        printf("\nList is empty\n");
 
    // Else print the LL
    else
    {
        temp = head;
        while (temp ->link!= NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->link;
        }
        printf("Data = %d\n", temp->data);
        
    }
}
 
// Function to insert at the front
// of the linked list
void insertAtFront()
{
    int value;
    struct node* temp, *newnode;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &value);
    newnode->data = value;
            if(head== NULL)
              {
                  newnode->link=NULL;
                  head=newnode;
              }
            else
{
    // Pointer of temp will be
    // assigned to head

    newnode->link = head;
    head = newnode;
}}
 
// Function to insert at the end of
// the linked list

void insertAtEnd()
{
    int value;
    struct node *temp=NULL, *newnode=NULL;
    newnode = malloc(sizeof(struct node));
 
    // Enter the number
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &value);
 
    // Changes links

    newnode->link = NULL;
    newnode->data = value;
            if(head== NULL)
              {
                  newnode->link=NULL;
                  head=newnode;
              }
            else
{
    temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newnode;
}}
 
// Function to insert at any specified
// position in the linked list
 void insertAtMiddle()
{
    struct node *temp, *newnode;

     int value, info ;

    newnode = malloc(sizeof(struct node));
    // enter the data for newnode
     scanf("%d",&value);
     newnode->data=value;
     newnode->link=NULL;
       
    // Enter the position and data
    printf("\nEnter   data  after which you want to insert:");
    scanf("%d",   &info);
 

    // Change Links
    temp = head;
     
    while (temp->data!=info)
    {
        temp = temp->link;
         
    }
     
    newnode->link = temp->link;
    temp->link = newnode;
}
 


// Function to delete from the front
// of the linked list


 void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head = temp->link;
        free(temp);
    }
}
 
// Function to delete from the end
// of the linked list
 void deleteEnd()
{
    struct node *temp=NULL, *prev=NULL;
    if (head == NULL)
        printf("\nList is Empty\n");
    else
    {
        temp = head;
        prev=head;
        while (temp->link != NULL)
        {
            prev = temp;
            printf("%d",temp->data);
            temp = temp->link;
        }
        
        prev->link = NULL;
        free(temp);
    }
}

//Dynamic
 
// Function to delete a node after a given value
 void deleteAtMiddle()
{
    struct node *temp, *prev;
     int info;
 
    // If LL is empty
    if (head == NULL)
        printf("\nList is empty\n");
 
    // Otherwise
    else
    {
        printf("\nEnter data  you want to delete : ");
  
        scanf("%d", &info);
         
        temp = head;
        prev= temp;
 
        // Traverse till node after which you want to insert
        while (temp->data!=info)
        {
             prev=temp;
            temp = temp->link;
 
        }
 
        // Change Links
        
        prev->link = temp->link;
        temp->link=NULL;
        // Free memory
        free(temp);
    }
}
 
 
// Driver Code
int main()
{
    int choice;
    while (1)
    {
 
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at"
               " heading\n");
        printf("\t3  For insertion at"
               " end\n");
        printf("\t4  For insertion at "
               "middle\n");
        printf("\t5  For deletion of "
               "first element\n");
        printf("\t6  For deletion of "
               "last element\n");
        printf("\t7  For deletion of "
               "element at middle\n");
        printf("t8  for searching a data\n");
        printf("\t9 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtMiddle();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteAtMiddle();
            break;
         
        case 9:
            exit(1);
            break;
        
        }
    }
    return 0;
}
