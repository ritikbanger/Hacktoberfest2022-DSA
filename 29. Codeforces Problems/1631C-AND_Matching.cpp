/*
https://codeforces.com/contest/1631/problem/C

You are given a set of n (n is always a power of 2) elements containing all integers 0,1,2,…,n−1 exactly once.

Find n2 pairs of elements such that:

Each element in the set is in exactly one pair.
The sum over all pairs of the bitwise AND of its elements must be exactly equal to k. Formally, if ai and bi are the elements of the i-th pair, then the following must hold:
∑i=1n/2ai&bi=k,
where & denotes the bitwise AND operation.
If there are many solutions, print any of them, if there is no solution, print −1 instead.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤400) — the number of test cases. Description of the test cases follows.

Each test case consists of a single line with two integers n and k (4≤n≤216, n is a power of 2, 0≤k≤n−1).

The sum of n over all test cases does not exceed 216. All test cases in each individual input will be pairwise different.

Output
For each test case, if there is no solution, print a single line with the integer −1.

Otherwise, print n2 lines, the i-th of them must contain ai and bi, the elements in the i-th pair.

If there are many solutions, print any of them. Print the pairs and the elements in the pairs in any order.

Example
input
4
4 0
4 1
4 2
4 3
output
0 3
1 2
0 2
1 3
0 1
2 3
-1
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
        
        int k;
        cin>>k;
        if(k == n-1 && n == 4)
            cout<<-1<<endl;
        else if(k == n-1){
            cout<<n-2<<" "<<n-1<<endl;
            cout<<1<<" "<<n-3<<endl;
            cout<<0<<" "<<2<<endl;
            int i = 3, j = n-4;
            while(i < j){
                cout<<i<<" "<<j<<endl;
                i++;
                j--;
            }
        }
        else{
            cout<<k<<" "<<n-1<<endl;
            int i = 1, j = n-2;
            while(i < j){
                if(i == k){
                    cout<<0<<" "<<j<<endl;
                }
                else if(j == k){
                    cout<<i<<" "<<0<<endl;
                }
                else{
                    cout<<i<<" "<<j<<endl;
                }
                i++;
                j--;
            }
        }

    }
    
    return 0;
}   

//      *        * * * * *
//     * *              *
//    *   *            *
//   *  *  *          *
//  *       *        *

