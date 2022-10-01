/*
https://codeforces.com/contest/1631/problem/B

You are given an array a of n elements. You can apply the following operation to it any number of times:

Select some subarray from a of even size 2k that begins at position l (1≤l≤l+2⋅k−1≤n, k≥1) and for each i between 0 and k−1 (inclusive), assign the value al+k+i to al+i.
For example, if a=[2,1,3,4,5,3], then choose l=1 and k=2, applying this operation the array will become a=[3,4,3,4,5,3].

Find the minimum number of operations (possibly zero) needed to make all the elements of the array equal.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤2⋅104) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤2⋅105) — the length of the array.

The second line of each test case consists of n integers a1,a2,…,an (1≤ai≤n) — the elements of the array a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
Print t lines, each line containing the answer to the corresponding test case — the minimum number of operations needed to make equal all the elements of the array with the given operation.

Example
input
5
3
1 1 1
2
2 1
5
4 4 4 2 4
4
4 2 1 3
1
1
output
0
1
1
2
0

*/


#include <bits/stdc++.h>
#include <string>

#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast();
    ll test;
    cin>>test;
    while(test--){

        int n;
        cin>>n;
        
        ll arr[n];
        
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        

        int count = 0;

        for(int i = n-2; i>=0; ){
            if(arr[i] == arr[i+1]){
                i--;
            }
            else{
                i = i -  (n - i - 1);
                if(i >= 0)
                arr[i+1] = arr[n-1];
                count++;
            }
        }

        cout<<count<<endl;
    }
    
    return 0;
}   

//      *        * * * * *
//     * *              *
//    *   *            *
//   *  *  *          *
//  *       *        *

