//dynamic program to sort the array using selection_sort

#include <bits/stdc++.h>
using namespace std;
 
//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min])
            min = j;
 
        // Swap the found minimum element with the first element
        if(min!=i)
            swap(&arr[min], &arr[i]);
    }
}
 
//Function to print an array

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//In this program you can give input by yourselft it is not static. It is the dynamic implementation of sorting.
