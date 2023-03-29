#include<stdio.h> 

int queue[100];
int front = -1;
int rear = -1;

void insert()
{
	int item;
	if(rear == 100-1)
	{
		printf("Overflow!\n");
	}
	else
	{
		if(front == -1)
		{
			front = 0;
		}
		printf("Insert the element in the queue : ");
		scanf("%d", &item);
		rear = rear+1;
		queue[rear] = item;
	}
}

void delete()
{
	if(front == -1 || front > rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("DELETED!\n");
		front = front + 1;
	}
}

void display()
{
	if(front == -1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(int i = front; i <=rear; i++)
		{
			printf("%d\t", queue[i]);
		}
	}
	printf("\n");
}

	
int main() 
{
	int choice;
	do 
	{	
		printf("1.Insert \n");
		printf("2.Delete \n");
		printf("3.Display \n");
		printf("4.Quit \n");
		scanf("%d", &choice);

		switch (choice) 
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				
			default:
				printf("Wrong choice \n");

		}
	}while(choice != 4);
}
