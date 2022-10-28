#include<stdio.h>

int main()
{
    int x,y,r,sum=0;
    printf("\n enter number ");
    scanf("%d",&x);
    y=x;
    while(x!=0)
    {
        r=x%10;
        sum = sum*10+r;
        x=x/10;
    }
    if(y==sum)
    printf("%d is palindrome",y);
    else
    printf("%d is not palindrome",y);
}
