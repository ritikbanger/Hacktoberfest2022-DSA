#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

void printlist(node* head){
    node* temp = head;
    if(head != NULL){
        do{
            printf("%d ", head->data);
            head = head->next;
        }while(head != temp);
    }
}

void insert_at_start(node** head){
    int new_data;
    printf("Enter data to enter:\n");
    scanf("%d", &new_data);

    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = *head;

    node* last = *head;
    if(*head != NULL){
        while(last->next != *head){
            last = last->next;
        }
        last->next = new_node;
    }else{
        new_node->next = new_node;
    }

    *head = new_node;
}

void insert_at_position(node** head){
    int pos, new_data;
    printf("Enter position to insert at:\n");
    scanf("%d", &pos);

    if(pos == 1){
        insert_at_start(head);
        return;
    }

    printf("Enter data to enter : \n");
    scanf("%d", &new_data);

    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = new_data;
    
    node* temp = *head;

    for(int i = 2; i<pos; i++){
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_at_end(node** head){
    int new_data;
    printf("Enter data to enter:\n");
    scanf("%d", &new_data);

    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = new_data;
    new_node->next = *head;

    node* last = *head;

    while(last->next != *head){
        last = last->next;
    }

    last->next = new_node;
}

void delete_from_start(node** head){
    node* temp = *head;

    node* last = *head;

    while(last->next != *head){
        last = last->next;
    }

    *head = temp->next;

    free(temp);

    last->next = *head;
}

void delete_from_position(node** head){
    int pos;
    printf("Enter position to delete from: \n");
    scanf("%d", &pos);

    if(pos == 1){
        delete_from_start(head);
        return;
    }

    node* temp = *head;

    for(int i = 2; i<pos; i++){
        temp = temp->next;
    }

    temp->next = temp->next->next;
}

void delete_from_end(node** head){
    node* last = *head;

    while(last->next->next != *head){
        last = last->next;
    }

    last->next = *head;
}

int main(){
    node* head = NULL;

    int choice;

    while(1){
        printf("\n\t1 Print List\n\t2 insert at beginning\n\t3 insert at any position\n\t4 insert at end\n\t5 delete from beginning\n\t6 delete from any position\n\t7 delete from end\n\t8 to exit\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printlist(head);
                break;
            case 2:
                insert_at_start(&head);
                break;
            case 3:
                insert_at_position(&head);
                break;
            case 4:
                insert_at_end(&head);
                break;
            case 5:
                delete_from_start(&head);
                break;
            case 6:
                delete_from_position(&head);
                break;
            case 7:
                delete_from_end(&head);
                break;
            case 8:
                exit(1);
                break;
            default:
                printf("Invalid Input\n");
        }   
    }
}