
#include <bits/stdc++.h>
using namespace std;


int countRotations(int arr[], int n)
{

	int min = arr[0], min_index = 0;
	for (int i = 0; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
			min_index = i;
		}
	}
	return min_index;
}


int main()
{
	int arr[] = { 14, 17, 2, 3, 5, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countRotations(arr, n);
	return 0;
}

