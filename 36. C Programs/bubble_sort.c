#define MAX 100
#include<stdio.h>
void Bubblesort(int [],int N);
int main()
{
int A[MAX],N;
printf("Enter the size of array :");
scanf("%d",&N);
for(int i=0;i<N;i++)
{
    scanf("%d",&A[i]);
}
Bubblesort(A,N);
for(int i=0;i<N;i++)
{
    printf("%d",A[i]);
}
}               
void Bubblesort(int A[],int N)
{
    int i,j,t;
    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
}                