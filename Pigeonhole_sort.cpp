#include <bits/stdc++.h>
using namespace std;
void pigeonholeSort(int arr[], int n)
{
	int min = arr[0], max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int range = max - min + 1; 
	vector<int> holes[range];
	for (int i = 0; i < n; i++)
		holes[arr[i]-min].push_back(arr[i]);
	int index = 0; 
	for (int i = 0; i < range; i++)
	{
	vector<int>::iterator it;
	for (it = holes[i].begin(); it != holes[i].end(); ++it)
			arr[index++] = *it;
	}
}

int main()
{
	int arr[] = {8, 3, 2, 7, 4, 6, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	pigeonholeSort(arr, n);

	printf("Sorted order is : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}

