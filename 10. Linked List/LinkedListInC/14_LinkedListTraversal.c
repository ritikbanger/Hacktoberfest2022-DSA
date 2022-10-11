#include<stdio.h>
#include<stdlib.h>

struct  Node
{
     int data;
     struct Node *next;
    
};

void linkedListTraversal(struct Node* ptr)  {    //  ham ek head node naam ka pointer lenge jo head ko point krega
                                                 // (head will be passed in argument from the main function at 
                                                 //  the time of the function call)     

    while(ptr != NULL) 
    {
    printf("Element : %d\n",ptr->data);   // ye intially pointer ke data ko print krega
    ptr = ptr->next;    // aur ye pointer ke data ko update krega next data m
    }
  
    }
int main() {

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

     // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third node
    second->data =11;
    second->next = third;

    // Link third and fourth node
    third->data = 66;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth-> data= 82;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;

}
