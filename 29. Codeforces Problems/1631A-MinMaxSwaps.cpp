/*
https://codeforces.com/contest/1631/problem/A

You are given two arrays a and b of n positive integers each. You can apply the following operation to them any number of times:

Select an index i (1≤i≤n) and swap ai with bi (i. e. ai becomes bi and vice versa).
Find the minimum possible value of max(a1,a2,…,an)⋅max(b1,b2,…,bn) you can get after applying such operation any number of times (possibly zero).

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100) — the length of the arrays.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10000) where ai is the i-th element of the array a.

The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤10000) where bi is the i-th element of the array b.

Output
For each test case, print a single integer, the minimum possible value of max(a1,a2,…,an)⋅max(b1,b2,…,bn) you can get after applying such operation any number of times.

Example
input
3
6
1 2 6 5 1 2
3 4 3 2 2 5
3
3 3 3
3 3 3
2
1 2
2 1
output
18
9
2

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
        
        ll a[n];
        ll b[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n; i++){
            cin>>b[i];
        }
        for(int i = 0; i<n; i++){
            if(a[i] < b[i])
                swap(a[i], b[i]);
        }

        ll maxa = a[0], maxb = b[0];
        for(int i = 0; i<n; i++){
            maxa = max(maxa, a[i]);
            maxb = max(maxb, b[i]);
        }
        cout<<maxa*maxb<<endl;

    }
    
    return 0;
}   

//      *        * * * * *
//     * *              *
//    *   *            *
//   *  *  *          *
//  *       *        *

