#include<conio.h>
#include<stdio.h>

int isprime(int val)
{
    int i ;
    if(val == 1)
        return 0;
    if(val==2||val%2==0)
        return (0);
    else
    {
        for(i = 3;i<=val/i;i=i+2)
        {
            if(val%i==0)
             return (0);
        }
        
    }

    return 1;
}
int main()
{
    int val,x;
    printf("\n Enter number : ");
    scanf("%d",&val);
    x = isprime(val);
    if(x == 1)
    {
        printf("\n it is prime");
    }
    else{
        printf("\n it is not prime");
    }
}
