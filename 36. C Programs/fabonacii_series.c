//fabonacii series

#include<stdio.h>
#include<conio.h>



int main()
{
  int n1=0,n2=1,n3,y;
  printf("\n enter how many fabonacii number you want : ");
  scanf("%d",&y);
  printf("%d %d ",n1,n2);

  for(int x=2; x<y;x++)
  {
    n3=n1+n2;
    printf(" %d ",n3);
    n1=n2;
    n2=n3;

  }
  return 0;
}
