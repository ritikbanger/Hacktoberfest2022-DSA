#include<stdio.h>

int main()
{
   int x,y;
   printf("\n enter numbers : ");
   scanf("%d%d",&x,&y);
   x=x*y;
   y=x/y;
   x=x/y;
   printf("\n enter numbers : %d %d ",x,y);
  
  return 0;
}
