#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int value)
{
	struct node *new = malloc(sizeof(struct node)) ;
	new->data=value;
	new->link = NULL;
	if(rear==NULL)
	{
		front=rear=new;
		rear->link=front;
	}	
	else
	{
		rear->link=new;
		rear=new;
		rear->link=front;
	}
	printf("Element %d has been inserted to the queue \n", new->data);
}

void dequeue()
{
	struct node *temp;
	temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("QUEUE is EMPTY \n");
	}
	else if (front==rear)
	{
		front=rear=NULL;
		printf("Element %d has been deleted from the queue \n", temp->data);
		free(temp);
	}
	else
	{
		front=front->link;
		rear->link=front;
		printf("Element %d has been deleted from the queue \n", temp->data);
		free(temp);
	}
	
	
}
int peek()
{
 if((front==NULL) && (rear==NULL))
 {
  printf("queue is empty\n");
 }
 else
 {
 printf("The front element is %d\n",front->data);
 }
 return 0;
}
void display()
{
	struct node *temp;
	temp=front;
	printf("elements in the queue are :");
	if ((front==NULL) && (rear==NULL))
{
  	printf("queue is empty\n");
 }
 	else
{
	while(temp->link!=front)
 {
 	printf("%d\n",temp->data);
 	temp=temp->link;
 }
 	printf("%d\n",temp->data);
}
}

void reverseq()   // reversing queue function
{
    if(front==NULL) 
    {
	printf("QUEUE is EMPTY \n");
	return;
    }

    struct node *current = front, *prev = rear, *next = front->link;
    
    do {
        current->link = prev;
        prev = current;
        current = next;
        next = next->link; 
      } 
      while (current != front);

    front = rear;
    rear = current;
}
int main(void)
{
	enqueue(10);
	enqueue(20);
	enqueue(30);       
	display();
        reverseq();  // applying reverse queue function
	display();   // checking the queue that it is reversed or not 
	return 0;
}

