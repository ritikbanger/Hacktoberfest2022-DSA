#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display_frwd(struct node *);
struct node *display_rev(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_pos(struct node *);
struct node *delete_list(struct node *);
struct node *count(struct node *);
struct node *reverse_list(struct node *);

int main()
{
    int option;
    //system("cls");
    do
    {
        printf("\n * MAIN MENU * \n");
        printf("1: Create a list\n");
        printf("2: Display the list in forward direction \n");
        printf("3: Display the list in reverse direction \n");
        printf("4: Add a node in the beginning\n");
        printf("5: Add a node at the end\n");
        printf("6: Insert before a given value\n");
        printf("7: Insert after a given value\n");
        printf("8: Delete a node from the beginning \n");
        printf("9: Delete a node from the end \n");
        printf("10: Delete the entire list \n");
        printf("12: Count nodes in the list \n");
        printf("13: Exit\n");
        printf("\n Enter your option: \n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            start = create_ll(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display_frwd(start);
            break;
        case 3:start=display_rev(start);
            break;
        case 4:
            start = insert_beg(start);
            break;
        case 5:
            start = insert_end(start);
            break;
        case 6:start=insert_before(start);
            break;
        case 7:start=insert_after(start);
            break;
        case 8: start = delete_beg(start);
            break;
        case 9: start = delete_end(start);
            break;
        case 10: start=delete_pos(start);
            break;
        case 11: start = delete_list(start);
            break;
        case 12: start=count(start);
            break;
        }
    } while(option!=12);
    //system("pause");
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter -1 to end \n");
    printf("Enter the data :");
    scanf("%d",&num);
    while(num!=(-1))
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start == NULL)
        {
            new_node -> next = NULL;
            new_node->prev=NULL; 
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node ->next=NULL;
            new_node->prev=ptr;
        }
        printf("\n Enter the data :");
        scanf("%d",&num);
    }
    return start;
}

struct node *display_frwd(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL)
    {
        printf("\t %d",ptr-> data);
        ptr = ptr -> next;
    }
    return start;
}
struct node *display_rev(struct node *start){
    struct node *ptr,*tail;
    ptr = start;
    while(ptr!=NULL)
    {
        tail=ptr;
        ptr = ptr -> next;
    }
    while(tail !=NULL){
        printf("\t %d",tail-> data);
        tail=tail->prev;
    }
    return start;
}
struct node *insert_beg(struct node *start){
    int num;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &num);
	temp->data = num;
	temp->prev = NULL;
	temp->next = start;
    start->prev=temp;
	return temp;
}
struct node *insert_end(struct node *start){
    int num;
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &num);
	temp-> data=num;
	trav = start;

	// If start is NULL
	if (start == NULL) {

		start = temp;
	}

	// Changes Links
	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
    return start;
}

struct node *delete_beg(struct node *start){
    struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
    return start;
}
struct node *delete_end(struct node *start){
    struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
    return start;
}
struct node *delete_pos(struct node *start)
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = start;

	// If DLL is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Otherwise
	else {
		// Position to be deleted
		printf("\nEnter position : ");
		scanf("%d", &pos);

		// If the position is the first node
		if (pos == 1) {
			start=delete_beg(start); 
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return start;
		}

		// Traverse till position
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		// Change Links
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;

		// Free memory
		free(position);
	}
    return start;
}
struct node *delete_list(struct node *start){
    struct node *ptr=start,*next_ptr;
    while(ptr->next !=NULL){
        next_ptr=ptr->next;
        free(ptr);
        ptr=next_ptr;
    }
    return NULL;
}
struct node *count(struct node *start){
    struct node* temp = start;
  int i = 0;
  while (temp != NULL) {
    i++;
    temp = temp->next;    
  }
  printf("There are %d nodes in the list\n",i);
  return start;    
}

struct node *insert_before(struct node *start){
    struct node *new_node, *ptr,*temp;
    int num,val;
    printf("\n Enter the data :");
    scanf("%d",&num);
    printf("Enter the value before which the data has to be inserted :");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val)
    {
        ptr = ptr -> next;
    }
    new_node -> next = ptr;
    new_node->prev=ptr->prev;
    ptr->prev -> next = new_node;
    ptr->prev=new_node;
    return start;
}
struct node *insert_after(struct node *start){
    struct node *new_node, *ptr;
    int num,val;
    printf("\n Enter the data :");
    scanf("%d",&num);
    printf("Enter the value after which the data has to be inserted :");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val)
    {
        ptr = ptr -> next;
    }
    new_node -> next = ptr->next;
    new_node->prev=ptr;
    ptr->next->prev=new_node;
    ptr->next=new_node;
    return start;
}
