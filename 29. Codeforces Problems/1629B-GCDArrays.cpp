/*
https://codeforces.com/contest/1629/problem/B

Consider the array a composed of all the integers in the range [l,r]. For example, if l=3 and r=7, then a=[3,4,5,6,7].

Given l, r, and k, is it possible for gcd(a) to be greater than 1 after doing the following operation at most k times?

Choose 2 numbers from a.
Permanently remove one occurrence of each of them from the array.
Insert their product back into a.
gcd(b) denotes the greatest common divisor (GCD) of the integers in b.

Input
The first line of the input contains a single integer t (1≤t≤105) — the number of test cases. The description of test cases follows.

The input for each test case consists of a single line containing 3 non-negative integers l, r, and k (1≤l≤r≤109,0≤k≤r−l).

Output
For each test case, print "YES" if it is possible to have the GCD of the corresponding array greater than 1 by performing at most k operations, and "NO" otherwise (case insensitive).

Example
input
9
1 1 0
3 5 1
13 13 0
4 4 0
3 7 4
4 10 3
2 4 0
1 7 3
1 5 3
output
NO
NO
YES
YES
YES
YES
NO
NO
YES

*/


#include <bits/stdc++.h>
#include <string>

#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int countOdd(int L, int R){
 
    int N = (R - L) / 2;
 
    if (R % 2 != 0 || L % 2 != 0)
        N += 1;
 
    return N;
}

int main(){
    fast();

    ll test;
    cin>>test;

    while(test--){
        ll l,r,k;
        cin>>l>>r>>k;
        if(l == 1 && r == 1){
            cout<<"NO"<<endl;
            continue;
        }
        else if(r-l == 1){
            if(k > 0){
                cout<<"YES"<<endl;
            continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }
        else if(r == l){
            cout<<"YES"<<endl;
            continue;
        }
        else if(k == 0){
            cout<<"NO"<<endl;
                continue;
        }
        else{
            int odd = countOdd(l,r);
            if(k >= odd){
                cout<<"YES"<<endl;
            continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
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

