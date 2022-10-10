//problem link-https://cses.fi/problemset/task/1637/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
//recursive+memoize
ll n;
ll dp[1000002];
ll calc(ll n)
{
    string s=to_string(n);
    if(n==0) return 0;
    ll &ans=dp[n];
    if(ans!=-1) return ans;
 
    ans=INT_MAX-1;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]!='0')
        {
        ans=min(ans,1+calc(n-(s[i]-'0')));
        }
    }
    return ans;
}
void solve()
{
   
   cin>>n;
   memset(dp,-1,sizeof dp);
   cout<<calc(n);
  
}
int main()
{
   
    fast;
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}
//sample input
//27

//sample output
//5