#include<stdio.h>
#include<stdlib.h>


struct Node {

    int data;
    struct Node * next;
};

void LinkedListTraversal(struct Node* ptr) {
       
       while(ptr!=NULL) {

        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
       }

}

int main(){

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;


    // Allocate memory dynamically to these pointers in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

   
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

    LinkedListTraversal(head);


    
    return 0;
}