#include <stdio.h>
#include <conio.h>
#include <Math.h>
float matrix[10][10], m, temp[10];
int i, j, k, n;
void lower_traingularisation() 
{
    for (i=n-1; i>0; i--)
    {
        for (j=i-1; j>=0; j--) 
        {
            m= matrix[j][i]/matrix[i][i];
            for (k=0; k<n+1; k++) 
            {
                matrix[j][k] = matrix[j][k]-(m*matrix[i][k]);
            }
        }
    }
}
void back_subsitution()
{
    for (i=0; i<n; i++)
    {
        m = matrix[i][n];
        for (j=0; j<i; j++)
            m = m - temp[j] * matrix[i][j];
        temp[i] = m/matrix[i][i];
        printf("\n x%d => %f", i+1, temp[i]);
    }
}
 
void main() 
{
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix: \n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n+1; j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%f", &matrix[i][j]);
        }
        printf("\n");
    }

    lower_traingularisation();
    printf("The lower traingular matrix is : \n");
    for (i=0; i<n; i++) 
    {
        for (j=0; j<n+1; j++)
            printf("%f \t", matrix[i][j]);
        printf("\n");
    }
    printf("\nThe required result is : \n");
    back_subsitution();
    getch();
} 
