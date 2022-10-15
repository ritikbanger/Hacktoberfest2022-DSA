/*
 link to Planet Queries I : https://cses.fi/problemset/task/1750/
 Time complexity: O(qlog(k)) where q is number of queires and k is number of teleports.
 Concept used: Binary Lifting 
*/

#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const double EPS = 1e-9;
const int INF = 2e9, MOD = 1e9 + 7;
const int N = 2e5 + 5, L = 31;

int dp[N][L];

int32_t main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    // dp[i][j] : node we will reach when we teleport 2^j from i.
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][0];
    }
    for (int i = 1; i < L; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < 31; i++)
        {
            if (k & (1ll << i)) {
                x = dp[x][i];
            }
        }
        cout << x << endl;
    }

    return 0;
}
