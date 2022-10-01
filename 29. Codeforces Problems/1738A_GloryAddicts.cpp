//problem link: https://codeforces.com/contest/1738/problem/A

#include <bits/stdc++.h>
using namespace std;

#define len(s) s.size()
#define ll long long
#define all(v) v.begin(), v.end()
#define nl '\n'

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

void solve()
{
    int n;
    cin >> n;
    ll a[n], b[n];
    vector<ll> aa, bb;
    ll sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum += b[i];
        if (a[i])
            bb.pb(b[i]);
        else
            aa.pb(b[i]);
    }
    if (!len(aa) || !len(bb))
    {
        cout << sum << nl;
        return;
    }
    ll ans1 = 0, ans2 = 0;
    sort(all(aa));
    sort(all(bb));
    reverse(all(aa));
    reverse(all(bb));
    if (len(aa))
        ans1 = aa.back();
    if (len(bb))
        ans2 = bb.back();
    int i = 0;
    //either 0 comes first or 1 , we take first element as min and rest in decreasing order.
    for (i = 0; i < min(len(bb), len(aa)); i++)
        ans1 += 2 * bb[i];
    for (; i < len(bb); i++)
        ans1 += bb[i];
    for (i = 0; i < min(len(bb), len(aa) - 1); i++)
        ans1 += 2 * aa[i];
    for (; i < len(aa) - 1; i++)
        ans1 += aa[i];
    for (i = 0; i < min(len(bb), len(aa)); i++)
        ans2 += 2 * aa[i];
    for (; i < len(aa); i++)
        ans2 += aa[i];
    for (i = 0; i < min(len(aa), len(bb) - 1); i++)
        ans2 += 2 * bb[i];
    for (; i < len(bb) - 1; i++)
        ans2 += bb[i];

    cout << max(ans1, ans2) << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve();
    }
}
