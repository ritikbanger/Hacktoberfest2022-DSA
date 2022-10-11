#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int front;
	int rear;
	int capacity;
	int * array;
};

struct Queue * create(int);
int QueueisEmpty(struct Queue *);
int QueueisFull(struct Queue *);

void enqueue(struct Queue *,int );
int dequeue(struct Queue *);
//int peek(struct Queue *);

void display1(struct Queue *);


struct Queue * create(int n)
{
	struct Queue * queue = (struct Queue *) malloc (sizeof(struct Queue));
	queue->rear = -1;
	queue->front = -1;
	queue->capacity=n;
	queue->array = (int *) malloc (sizeof(int) * n);
	return queue;
}	

int QueueisEmpty(struct Queue * queue)
{
	if(queue->front>queue->rear)
	{
		queue->front=-1;
		queue->rear=-1;
		return 1;
	}
	else if(queue->front<0)
		return 1;	
	else 
		return 0;
}

int QueueisFull(struct Queue * queue)
{
	if(queue->rear == queue->capacity-1)
		return 1;
	else
		return 0;
}

void enqueue(struct Queue * queue,int n)
{
	if(QueueisFull(queue))
	{
		printf("Overflow!\n");
		return;
	}
	if(queue->front==-1)
		queue->front=0;
	queue->array[++queue->rear] = n;
}

int dequeue(struct Queue * queue)
{
	if(QueueisEmpty(queue))
	{
		printf("Underflow!\n");
		return -1;
	}
	int x = queue->array[queue->front];
	queue->front++;
	return x;
}

void display1(struct Queue * queue)
{
	struct Queue * q = create(queue->capacity);
	q->rear = queue->rear;
	q->front = queue->front;
	q->capacity = queue->capacity;
	q->array = queue->array;
	if(QueueisEmpty(q))
	{
		//printf("No elements in the queue\n");
		return;
	}	
	printf("%d\n",dequeue(q));
	display1(q);
} 



struct Graph
{
	int vertex;
	int edge;
	int ** adjMatrix;
};

struct Graph * createGraph(int v, int e)
{
	int i, j;
	struct Graph * g;
	g = (struct Graph *)malloc(sizeof(struct Graph));

	g->vertex = v;
	g->edge = e;
	g->adjMatrix = (int **)malloc(v * sizeof(int *));

	for(i = 0; i < v; i++)
	{
		g->adjMatrix[i] = (int *)malloc(v * sizeof(int));
		for(j = 0; j < v; j++)	
			g->adjMatrix[i][j] = 0;
	}
	return g;
}

struct Graph * insertEdge(struct Graph * g, int v1, int v2)
{
	//undirected graph
	g->adjMatrix[v1][v2] = 1;
	
	g->adjMatrix[v2][v1] = 1;
	//for directed graph- remove line no 37
	return g;
}

void printGraph(struct Graph * g)
{
	int i, j;
	for(i = 0; i < g->vertex; i++)
	{
		for(j = 0; j < g->vertex; j++)
		{
			printf("%d  ", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void recursiveBFS(struct Graph * g,struct Queue * q, int * visited)
{
	int i, x;
	
	if(QueueisEmpty(q))
		return;
	x=dequeue(q);
	printf("%d->",x);
	
	for(i=0;i<g->vertex;i++)
	{
		if(g->adjMatrix[x][i] == 1)
		{
		
			if(!visited[i])
			{
				visited[i]=1;
				enqueue(q,i);
			}
		}
	}
	recursiveBFS(g,q,visited);
}
	
int main()
{
    int n, e, v1, v2, i;
    int * visited;
	struct Graph * g;
	
	printf("\nEnter the number of node and number of edge : ");
	scanf("%d%d",&n,&e);
	g = createGraph(n,e);
    printf("Enter the %d Edges",e);
    for(i=0; i<e; i++)
    {
    	printf("\nEnter the source node and destination node: ");
    	scanf("%d%d",&v1,&v2);
    	g = insertEdge(g,v1,v2);
    }

    printGraph(g);
    visited = (int *)malloc(n*sizeof(int));
	
	for(i = 0; i<n; i++)
		visited[i] = 0;
    struct Queue * queue= create(n);
    printf("enter the value from which you want to start : ");
    scanf("%d",&i);
    
    if(visited[i]==0)
    {
    	visited[i]=1;
    	enqueue(queue,i);
    	recursiveBFS(g,queue,visited);
    }
    
    return 0;
}