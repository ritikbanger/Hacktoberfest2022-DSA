/*

https://codeforces.com/contest/1632/problem/B

It has finally been decided to build a roof over the football field in School 179. Its construction will require placing n consecutive vertical pillars. Furthermore, the headmaster wants the heights of all the pillars to form a permutation p of integers from 0 to n−1, where pi is the height of the i-th pillar from the left (1≤i≤n).

As the chief, you know that the cost of construction of consecutive pillars is equal to the maximum value of the bitwise XOR of heights of all pairs of adjacent pillars. In other words, the cost of construction is equal to max1≤i≤n−1pi⊕pi+1, where ⊕ denotes the bitwise XOR operation.

Find any sequence of pillar heights p of length n with the smallest construction cost.

In this problem, a permutation is an array consisting of n distinct integers from 0 to n−1 in arbitrary order. For example, [2,3,1,0,4] is a permutation, but [1,0,1] is not a permutation (1 appears twice in the array) and [1,0,3] is also not a permutation (n=3, but 3 is in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The only line for each test case contains a single integer n (2≤n≤2⋅105) — the number of pillars for the construction of the roof.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case print n integers p1, p2, …, pn — the sequence of pillar heights with the smallest construction cost.

If there are multiple answers, print any of them.

Example
input
4
2
3
5
10
output
0 1
2 0 1
3 2 1 0 4
4 6 3 2 0 8 9 1 7 5

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
        
        if(n == 1){
            cout<<0<<endl;
        }
        else if(n == 2){
            cout<<0<<" "<<1<<endl;
        }
        else
        {
            int x = n-1;
            if(x&(x-1) == 0){
                for(int i = x; i>=1; i--){
                    cout<<i<<" ";
                }
                cout<<0<<" "<<x<<endl;

            }
            else{
                    int x = n-1; 
                    int t = pow(2, (int)log2(x));
                    for(int i = n-1; i>t; i--){
                        cout<<i<<" ";
                    }
                    cout<<t<<" "<<0<<" ";
                    for(int i = 1; i<t; i++){
                        cout<<i<<" ";
                    }
                    cout<<endl;
                    
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

