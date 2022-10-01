/*
https://codeforces.com/contest/1633/problem/B

Explanation: You are given a string s, consisting only of characters '0' and '1'.

You have to choose a contiguous substring of s and remove all occurrences of the character, which is a strict minority in it, from the substring.

That is, if the amount of '0's in the substring is strictly smaller than the amount of '1's, remove all occurrences of '0' from the substring. If the amount of '1's is strictly smaller than the amount of '0's, remove all occurrences of '1'. If the amounts are the same, do nothing.

You have to apply the operation exactly once. What is the maximum amount of characters that can be removed?

Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

The only line of each testcase contains a non-empty string s, consisting only of characters '0' and '1'. The length of s doesn't exceed 2⋅105.

The total length of strings s over all testcases doesn't exceed 2⋅105.

Output
For each testcase, print a single integer — the maximum amount of characters that can be removed after applying the operation exactly once.

Example
input
4
01
1010101010111
00110001000
1
output
0
5
3
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

        string s;
        cin>>s;
        if(s.size() == 1 or s.size() ==2)
        {
            cout<<0<<endl;
        }
        else{
            int zer = 0;
            int on = 0;
            for(int i = 0; i<s.size(); i++){
                if(s[i] == '0'){
                    zer++;
                }
                else{
                    on++;
                }
            }
            if(zer != on)
            cout<<min(zer, on)<<endl;
            else
                cout<<zer-1<<endl;
        }
    }
    
    return 0;
}   

//      *        * * * * *
//     * *              *
//    *   *            *
//   *  *  *          *
//  *       *        *

