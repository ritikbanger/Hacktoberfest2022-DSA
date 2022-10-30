#include<stdio.h>

void fib(int n,int a,int b,int j);
void main()
{
	int size,x=0,y=1,i=1;
	printf("Enter number of entries: ");
	scanf("%d", &size);
	printf("%d ",x);
	fib(size,x,y,i); 
}

void fib(int n,int a,int b,int j)
{
	int s;
	if(j<n)
	{
		s=a+b;
		a=b;
		b=s;
		printf("%d  ",s);
		j++;
		fib(n,a,b,j);
	} 
	printf("\n");
}
