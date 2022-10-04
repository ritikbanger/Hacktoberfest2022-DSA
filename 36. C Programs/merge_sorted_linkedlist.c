#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

void insert(node** head, int new_data){
    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = new_data;
    new_node->next = NULL;

    node* last = *head;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

void displaylist(node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3 = NULL;

    int size1, size2;

    printf("Enter size for list 1 and 2:\n");
    scanf("%d %d", &size1, &size2);

    printf("Enter data for list 1:\n");
    int x, y;
    for(int i = 0; i<size1; i++){
        scanf("%d", &x);
        insert(&head1, x);
    }

    printf("Enter data for list 2:\n");
    for(int i = 0; i<size2; i++){
        scanf("%d", &y);
        insert(&head2, y);
    }

    int size3 = size1 + size2;
    int zz;

    node* temp1 = head1;
    node* temp2 = head2;

    for(int i = 0; i<size3; i++){
        if((temp1) == NULL){
            zz = temp2->data;
            insert(&head3, zz);
            temp2 = temp2->next;
        }else if((temp2) == NULL){
            zz = temp1->data;
            insert(&head3, zz);
            temp1 = temp1->next;
        }else if((temp1)->data < (temp2)->data){
            zz = (temp1)->data;
            insert(&head3, zz);
            temp1 = (temp1)->next;
        }else{
            zz = (temp2)->data;
            insert(&head3, zz);
            (temp2) = (temp2)->next;
        }
    }
    printf("The merged linkedlist of two sorted array is:\n");
    printf("Sorted array 1 :\n");
    displaylist(head1);
    printf("Sorted array 2 :\n");
    displaylist(head2);
    printf("Merged array :\n");
    displaylist(head3);
}