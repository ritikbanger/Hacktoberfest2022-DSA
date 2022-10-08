#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

void printlist(node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void insert_at_start(node** head){
    int new_data;
    printf("Enter the data to be stored: \n");
    scanf("%d", &new_data);

    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = new_data;
    new_node->next = *head;

    *head = new_node;
}

void insert_at_middle(node** head, int pos){
    node* prev_node = *head;

    if(pos == 1 && prev_node != NULL){
        insert_at_start(head);
        return;
    }

    for(int i = 2; i<pos; i++){
        if(prev_node->next != NULL){
            prev_node = prev_node->next;
        }
    }

    if(prev_node == NULL){
        printf("The previous node given cannot be NULL\n");
        return;
    }

    int new_data;
    printf("Enter the data to be stored: \n");
    scanf("%d", &new_data);

    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void insert_at_end(node** head){
    int new_data;
    printf("Enter the data to be stored: \n");
    scanf("%d", &new_data);

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
    return;
}

void delete_from_start(node** head){
    node* temp = *head;

    *head = temp->next;

    free(temp);
}

void delete_from_position(node** head, int pos){
    node* prev_node = *head;

    if(pos == 1){
        delete_from_start(head);
        return;
    }

    for(int i = 2; i<pos; i++){
        if(prev_node->next != NULL){
            prev_node = prev_node->next;
        }
    }

    prev_node->next = prev_node->next->next;
}

void delete_from_end(node** head){
    node* last = *head;

    while(last->next->next != NULL){
        last = last->next;
    }

    last->next = NULL;
}

void reverse(node** head){
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while(current != NULL){
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    *head = prev;

    printf("The reversed list is: \n");
    while(prev != NULL){
        printf("%d ", prev->data);
        prev = prev->next;
    }
}

int main(){
    node* head = NULL;

    int choice, pos;

    while(1){
        printf("\n\t1 To see the created list\n");
        printf("\t2 To enter at the start\n");
        printf("\t3 To enter at any position\n");
        printf("\t4 To enter at the end\n");
        printf("\t5 To delete from the start\n");
        printf("\t6 To delete from any position\n");
        printf("\t7 To delete from end\n");
        printf("\t8 To reverse the list\n");
        printf("\t9 To exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printlist(head);
            break;
        
        case 2:
            insert_at_start(&head);
            break;

        case 3:
            printf("Enter the position to insert at: \n");
            scanf("%d", &pos);
            insert_at_middle(&head, pos);
            break;

        case 4:
            insert_at_end(&head);
            break;

        case 5:
            delete_from_start(&head);
            break;

        case 6:
            printf("Enter Position to delete: \n");
            scanf("%d", &pos);
            delete_from_position(&head, pos);
            break;

        case 7:
            delete_from_end(&head);
            break;

        case 8:
            reverse(&head);
            break;

        case 9:
            exit(1);
            break;
        
        default:
            printf("Invalid choice entered.\n");
            break;
        }
    }
}