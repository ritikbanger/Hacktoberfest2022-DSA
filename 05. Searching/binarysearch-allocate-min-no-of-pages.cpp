#include<iostream>
#include<math.h>
using namespace std;
bool isFesiable(int arr[] , int N , int K , int ans)
{
    int req = 1 ;
    int sum = 0 ;
    for(int i =0;i<N;i++)
    {
        if (sum+arr[i]>ans)
        {
            req++ ;
            //cout<<req<<" " ;
            sum = arr[i] ;
        }
        else{
            sum = sum + arr[i] ;
        }
    }
    return (req<=K) ;
}

    int findPages(int arr[], int N, int K)
    {
        //code here
        int sum = 0 ;
        int max1 = 0 ;
        for(int i = 0 ;i<N;i++)
        {
            sum = sum + arr[i] ;
            max1 = max(max1 , arr[i]) ;
        }
        int low = max1;
        int high = sum ;
        int res = 0 ;
        while(low<=high)
        {
            int mid = floor((low+high)/2);
            //cout<<mid<<" " ;
            if (isFesiable(arr , N , K , mid))
            {
                res = mid ;
                //cout<<res<<endl ;
                high = mid - 1 ;
            }
            else
            {
                low =  mid + 1 ;
            }

        }
        return res ;
    }

int main()
{
    int arr[4] = {12,34,67,90};
    int result = findPages(arr,4,2);
    cout<<result ;
}
