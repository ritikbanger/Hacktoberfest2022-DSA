#include <stdio.h>
void quicksort(int a[], int low, int high)
{
    int pivot = a[(high + low) / 2];
    int l = low;
    int h = high;
    while (l <= h)
    {
        while (a[l] < pivot)
        {
            l++;
        }
        while (a[h] > pivot)
        {
            h--;
        }
        if (l <= h)
        {
            int t = a[l];
            a[l] = a[h];
            a[h] = t;
            l++;
            h--;
        }
    }
    if (low < h)
        quicksort(a, low, h);
    if (l < high)
        quicksort(a, l, high);
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("How many elements are u going to enter?: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("Order of Sorted elements: ");
    print(a, n);
}