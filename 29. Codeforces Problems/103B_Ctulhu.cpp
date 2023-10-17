#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;
#define ll long long
#define MOD 998244353
int cycle_count = 0;
void dfs(ll node, vector<vector<ll>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for (auto i : adj[node])
    {
        if (vis[i] == false)
        {
            dfs(i, adj, vis);
        }
    }
    return;
}
void dfs_cycle_check(ll node, vector<vector<ll>> &adj, ll par, vector<bool> &vis)
{
    vis[node] = true;
    for (auto i : adj[node])
    {
        if (vis[i] == true && i != par)
        {
            cycle_count++;
        }
        else if (vis[i] == false)
        {
            dfs_cycle_check(i, adj, node, vis);
        }
    }
    return;
}
void solve()
{
    // CHECK IF ALL NODES ARE PART OF A SINGLE COMPONENT
    // CHECK IF THE NUMBER OF CYCLES IS ONE
    // QUESTION LINK: https://codeforces.com/problemset/problem/103/B
    
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adjl(n + 1);
    ll u, v;
    vector<bool> vis(n + 1, false);
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    bool flag = false;
    for (ll i = 1; i < n + 1; i++)
    {
        if (vis[i] == false && flag == true)
        {
            cout << "NO" << endl;
            return;
        }
        else if (vis[i] == false)
        {
            flag = true;
            dfs(i, adjl, vis);
        }
    }
    fill(vis.begin(), vis.end(), false);
    dfs_cycle_check(1, adjl, -1, vis);
    // cycle_count = original cycle count * 2 as one connection is counted twice
    if (cycle_count == 2)
    {
        cout << "FHTAGN!" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}
int main()
{
    IOS;
    ll t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
