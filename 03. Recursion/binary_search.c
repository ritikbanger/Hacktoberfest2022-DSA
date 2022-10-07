#include <stdio.h>
int binarySearch(int array[], int x, int low, int high) {
 if (high >= low) {
 int mid = low + (high - low) / 2;
 // If found at mid, then return it
 if (array[mid] == x)
 return mid;
 // Search the left half
 if (array[mid] > x)
 return binarySearch(array, x, low, mid - 1);
 // Search the right half
 return binarySearch(array, x, mid + 1, high);
 }
 return -1;
}
int main(void) {
 int array[30];
 int n;
 printf("The size of array: ");
 scanf("%d",&n);
 for(int i=0; i<n; i++)
 {
     printf("Enter the element %d :",i+1);
     scanf("%d",&array[i]);
 }
 int x;
 printf("Enter the number to be found: ");
 scanf("%d",&x);
 int result = binarySearch(array, x, 0, n - 1);
 if (result == -1)
 printf("Not found");
 else
 printf("Element is found at index %d", result);
}
