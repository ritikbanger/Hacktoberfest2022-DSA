#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include <unordered_map>
#include<climits>
#include<set>
#include <iomanip>
#include<numeric>
#include<queue>
#include<stack>
#include <map>
#include<bitset>
using namespace std;
#define ll long long
#define endl "\n" 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n*n];
        for(ll i=0;i<n*n;i++)
        cin>>arr[i];
        sort(arr,arr+n*n);
        vector<ll> v;
        ll i=0,ans=n/2;
        ll sum=0;
        if(n==1)
        {
            if(arr[0]<k)
            {
                cout<<arr[0]<<endl;
                continue;
            }
            cout<<-1<<endl;
            continue;
        }
        while(i<n)
        {
            sum+=arr[ans];
            v.push_back(ans);
            i++;
            ans+=(n/2+1);
        }
        if(sum>k)
        {
            cout<<-1<<endl;
            continue;
        }
        ll pre[n*n];
        pre[0]=arr[0];
        for(ll i=1;i<n*n;i++)
        pre[i]=pre[i-1]+arr[i];
        ll pre1[n];
        pre1[0]=arr[v[0]];
        for(ll i=1;i<n;i++)
        pre1[i]=pre1[i-1]+arr[v[i]];
        ll a=k-sum;
        if(a==0)
        {
            cout<<arr[v[0]]<<endl;
            continue;
        }
        ll flag=0;
        for(ll i=0;i<n-1;i++)
        {
            for(ll j=v[i];j<v[i+1];j++)
            {
                ll temp=pre[j]-pre[j-i-1];
                if(temp-pre1[i]<=a)
                {
                    flag=1;
                    ans=max(ans,arr[j-i]);
                }
            }
        }
        if(pre[v[n-1]]-pre[v[n-1]-n]<=a)
        {
            cout<<arr[v[n-1]-n+1]<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}
