/*
https://codeforces.com/contest/1629/problem/A

Did you know you can download more RAM? There is a shop with n different pieces of software that increase your RAM. The i-th RAM increasing software takes ai GB of memory to run (temporarily, once the program is done running, you get the RAM back), and gives you an additional bi GB of RAM (permanently). Each software can only be used once. Your PC currently has k GB of RAM.

Note that you can't use a RAM-increasing software if it takes more GB of RAM to use than what you currently have.

Since RAM is the most important thing in the world, you wonder, what is the maximum possible amount of RAM achievable?

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of test cases follows.

The first line of each test case contains the integers n and k (1≤n≤100, 1≤k≤1000). Then two lines follow, each containing n integers describing the arrays a and b (1≤ai,bi≤1000).

Output
For each test case, output a single line containing the largest amount of RAM you can achieve.

Example
input
4
3 10
20 30 10
9 100 10
5 1
1 1 5 1 1
1 1 1 1 1
5 1
2 2 2 2 2
100 100 100 100 100
5 8
128 64 32 16 8
128 64 32 16 8
output
29
6
1
256
*/



#include <bits/stdc++.h>
#include <string>

#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast();

    int test;
    cin>>test;

    while(test--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            cin>>v[i].first;
        }
        for(int i = 0; i<n; i++){
            cin>>v[i].second;
        }
        sort(v.begin(), v.end());

        
        for(int i = 0; i<n; i++){
            if(k < v[i].first){
                break;
            }
            k += v[i].second;
        }
        cout<<k<<endl;
    }
    
    return 0;
}   

//      *        * * * * *
//     * *              *
//    *   *            *
//   *  *  *          *
//  *       *        *

