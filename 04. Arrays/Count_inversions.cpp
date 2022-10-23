#include <bits/stdc++.h>
using namespace std;
long long int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long int inversionCount(vector<long long> arr, long long N) {
    // Your Code Here
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        inv_count += inversionCount(arr, temp, left, mid);
        inv_count += inversionCount(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
int main() {
    long long n;
    cin >> n;
    vector<long long> arr;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    long long int res = inversionCount(arr, n);
    cout << res << endl;
}