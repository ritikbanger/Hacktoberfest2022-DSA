#include <iostream>
using namespace std;
int BS(int A[] , int s ,int e,int key)
{
    
        int mid = (s+e)/2;
        if(A[mid]==key)
        return mid;
        else
        if(key<A[mid])
         return BS(A,s,mid-1,e);
        else
         return BS(A,mid+1,e,key);
}
int main()
{
    int A[10] = {2,3,4,5,6,7};
   cout<<BS(A,0,5,6);

}