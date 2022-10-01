/*
https://codeforces.com/contest/1633/problem/A

You are given an integer n. You have to change the minimum number of digits in it in such a way that the resulting number does not have any leading zeroes and is divisible by 7.

If there are multiple ways to do it, print any of them. If the given number is already divisible by 7, leave it unchanged.

Input
The first line contains one integer t (1≤t≤990) — the number of test cases.

Then the test cases follow, each test case consists of one line containing one integer n (10≤n≤999).

Output
For each test case, print one integer without any leading zeroes — the result of your changes (i. e. the integer that is divisible by 7 and can be obtained by changing the minimum possible number of digits in n).

If there are multiple ways to apply changes, print any resulting number. If the given number is already divisible by 7, just print it.

Example
input
3
42
23
377
output
42
28
777

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
        if(n == 0)
        {
            cout<<7<<endl;
        }
        else if(n%7 == 0){
        cout<<n<<endl;
        }
        else{
            string s = to_string(n);
            int len = s.length();
            for(int i = 0; i<=9; i++){
                s[len-1] = '0' + i;
                if(stoi(s)%7 == 0){
                    cout<<s<<endl;
                    break;
                }
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
