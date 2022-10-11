#include<stdio.h>
#include<stdlib.h>

struct  Node
{
     int data;
     struct Node *next;
    
};

void linkedListTraversal(struct Node* ptr)  {  // pointer for traversal in Linked list

    while(ptr != NULL) {
    printf("Element : %d\n",ptr->data);
    ptr = ptr->next;

    }
  
    }

 struct Node *insertAtEnd(struct Node *head,int data) {
     struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
     struct Node *p=head;

     ptr -> data = data;

      

      while(p->next!=NULL) {
          p=p->next;

      }

      p->next = ptr;
      ptr->next = NULL;
      return head;

   


   
 }    


int main() {

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocate memeory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

     // Link first and third nodes
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

   printf("Linked List before insertion\n");
    linkedListTraversal(head);
    head = insertAtEnd(head,56);
    printf("\n");
    printf("Linked list after insertion\n");
;    linkedListTraversal(head);

    return 0;

}
