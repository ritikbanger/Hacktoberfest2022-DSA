/*
https://codeforces.com/contest/1632/problem/A

Recently, the students of School 179 have developed a unique algorithm, which takes in a binary string s as input. However, they soon found out that if some substring t of s is a palindrome of length greater than 1, the algorithm will work incorrectly. Can the students somehow reorder the characters of s so that the algorithm will work correctly on the string?

A binary string is a string where each character is either 0 or 1.

A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

A palindrome is a string that reads the same backwards as forwards.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤100) — the length of the string s.

The second line of each test case contains the string s of length n consisting only of the characters 0 and 1.

Output
For each test case, print YES (case-insensitive) if it is possible to reorder the characters of s so that there are no substrings that are a palindrome of length greater than 1, or NO (case-insensitive) otherwise.

Example
input
4
1
1
2
10
2
01
4
1010
output
YES
YES
YES
NO

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
        string str;
        cin>>ws;
        cin>>str;

        if(n == 1)
            cout<<"YES"<<endl;
        else if(n == 2){
            if(str == "01" or str == "10")
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    
    return 0;
}   

//      *        * * * * *
//     * *              *
//    *   *            *
//   *  *  *          *
//  *       *        *

