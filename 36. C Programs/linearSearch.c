#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
   int arr[]={1,2,3,4,5,6,5,8,9};
   printf("enter the element you want to find\n");
   int num, find=1;
   scanf("%d",&num);
   for (int i = 0; i <= 8 ;i++)
   {
       if (num == arr[i] )
       {    find=0;

          printf("Array index is %d \n",i);
          continue;
       }
   }
    // if(!(find))printf("element not present");
    return 0;
}