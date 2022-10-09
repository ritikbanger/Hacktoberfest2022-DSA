// Solution for Codechef Problem: Make A and B equal:
// https://www.codechef.com/problems/MAKEABEQUAL

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll sa = 0, sb = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sa += a[i]*1LL;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            sb += b[i]*1LL;
        }
        
        if (sa != sb)
        {
            cout << "-1\n";
            continue;
        }
        vector<ll> maxi(n);
        for (int i = 0; i < n; i++) maxi[i] = max(a[i], b[i]);        
        ll op1 = 0, op2 = 0;
        
        for (int i = 0; i < n; i++)
        {
            op1 += (maxi[i]*1LL - a[i]);
            op2 += (maxi[i]*1LL - b[i]);
        }
        
        if (op1 == op2) {
          cout << op1 << nline;
        }
        else cout << "-1\n";        
    }   

    return 0;
}
