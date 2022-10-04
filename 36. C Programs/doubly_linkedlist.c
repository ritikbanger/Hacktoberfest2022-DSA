#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
} node;

void insert_at_start(node** head){
    node* new_node = (node*)malloc(sizeof(node));

    int new_data;
    printf("Enter new data to enter: \n");
    scanf("%d", &new_data);

    new_node->data = new_data;
    new_node->next = *head;

    if(*head != NULL){
        (*head)->prev = new_node;
    }
    new_node->prev = NULL;

    *head = new_node;
}

void insert_at_position(node** head){
    int pos;
    printf("Enter position to insert at: \n");
    scanf("%d", &pos);

    if(pos < 1){
        printf("Invalid position\n");
        return;
    }

    if(pos == 1){
        insert_at_start(head);
        return;
    }

    node* new_node = (node*)malloc(sizeof(node));

    int new_data;
    printf("Enter data to enter:\n");
    scanf("%d", &new_data);

    new_node->data = new_data;

    node* last = *head;

    if(last == NULL){
        if(pos != 1){
            printf("Invalid position\n");
            return;
        }
        *head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        return;
    }

    for(int i = 2; i<pos; i++){
        if(last == NULL){
            printf("Invalid position\n");
            return;
        }
        last = last->next;
    }

    new_node->next = last->next;
    new_node->prev = last;

    last->next = new_node;
    if(new_node->next != NULL){
        new_node->next->prev = new_node;
    }
}

void insert_at_end(node** head){
    int new_data;
    printf("Enter data to insert: \n");
    scanf("%d", &new_data);

    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;

    node* last = *head;

    if(last == NULL){
        *head = new_node;
        new_node->prev = NULL;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void delete_from_start(node** head){
    if(*head == NULL){
        printf("Empty list\n");
        return;
    }

    if((*head)->next == NULL){
        *head = NULL;
        return;
    }

    node* temp = *head;

    if(temp->next != NULL){
        *head = temp->next;
        temp->next->prev = NULL;    
    }

    free(temp);
}

void delete_from_position(node** head){
    if(*head == NULL){
        printf("Empty list\n");
        return;
    }

    int pos;
    printf("Enter position to delete:\n");
    scanf("%d", &pos);

    if(pos < 1){
        printf("Invalid position\n");
        return;
    }

    if(pos == 1){
        delete_from_start(head);
        return;
    }

    node* last = *head;

    for(int i = 2; i < pos; i++){
        if(last->next->next == NULL){
            printf("Invalid position\n");
            return;
        }

        last = last->next;
    }

    last->next = last->next->next;
    if(last->next != NULL){
        last->next->prev = last;
    }
}

void delete_from_end(node** head){
    if(*head == NULL){
        printf("Empty list\n");
        return;
    }

    node* last = *head;

    while(last->next->next != NULL){
        last = last->next;
    }

    last->next = NULL;
}

void displaylist(node* head){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    node* temp = head;
    while(head != NULL){
        if(head->next == NULL){
            temp = head->prev;
        }
        printf("%d ", head->data);
        head = head->next;
    }
    head = temp;
    while(head != NULL){
        printf("%d ", head->data);
        head = head->prev;
    }
}

int main(){
    node* head = NULL;

    int choice;
    while(1){
        printf("\n\t1 Display\n\t2 insert at start\n\t3 insert at any position\n\t4 insert at end\n\t5 delete from start\n\t6 delete from any position\n\t7 delete from end\n\t8 to exit\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                displaylist(head);
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
                printf("Invalid Choice\n");
        }
    }
}