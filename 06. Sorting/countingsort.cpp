#include <iostream>
using namespace std;
int countingsort(int A[],int n, int k){
    
    int C[20] = {0};
     int  B[20];
    
    for(int i =0 ; i<=n-1 ; i++){
        C[A[i]]++;         //counting
    }
    for(int i =1 ; i<=k ; i++){
        C[i] = C[i] + C[i-1]; //cummulative sum
}

    for(int i =n-1 ; i>=0 ; i--)
    {
   B[C[A[i]]-1] = A[i];      //sequential arrangement
   C[A[i]] = C[A[i]]-1;    //decreament 
    }
    for(int i = 0 ; i<=n-1 ; i++){
        cout<<B[i];
    }

}  

int main()
{
int A[20] = { 7,3,5,6,9,4,6,1,2,8};
int n = 10;
int k = 9 ;
countingsort(A ,n ,k);

}