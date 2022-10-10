// Given a positive number k, we need to find a minimum value of positive integer n, such that XOR of n and n+1 is equal to k. If no such n exist then print -1.
// Level: Medium

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    int xorCal(int k)
    {
        for (int i = 1; i <= 100; i++)
        {
            if ((i ^ i + 1) == k)
                return i;
        }
        return -1;
        // code here
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;

        Solution ob;
        cout << ob.xorCal(k) << "\n";
    }
    return 0;
}