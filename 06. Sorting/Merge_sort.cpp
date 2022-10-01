#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void print_array(int array[],int left,int right){
    int i;
    for (i=left; i <= right; i++)
        cout<<array[i]<<'\t';
    cout<<endl;
}

void merge(int array[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;

    int Left[n1], Right[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        Left[i] = array[left + i];
    for (j = 0; j < n2; j++)
        Right[j] = array[mid + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (Left[i] <= Right[j])
            array[k++] = Left[i++];
        else
            array[k++] = Right[j++];
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
        array[k++] = Left[i++];

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
        array[k++] = Right[j++];
}

void mergeSort(int array[], int left, int right){
    int i;
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}


int main(){
    int array[] = {24, 17, 13, 22, 19, 21, 16, 12};
    int array_size = sizeof(array)/sizeof(array[0]);
    int i;

    cout<<"Given array is :\n";
    print_array(array,0,array_size-1);
    mergeSort(array, 0, array_size - 1);
    cout<<"\nSorted array is :\n";
    print_array(array,0,array_size-1);
    return 0;
}
