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

 

 struct Node *insertAtIndex(struct Node *head,int data,int index) {
      struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
      struct Node *p=head;

      int i=0;

      while(i!=index-1) {

        p = p->next;
        i++;
      }
      ptr->data = data;
      ptr->next = p->next;
      p->next = ptr;
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

    linkedListTraversal(head);
    head = insertAtIndex(head,56,1);
    printf("\n"); 
    linkedListTraversal(head);

    return 0;

}
