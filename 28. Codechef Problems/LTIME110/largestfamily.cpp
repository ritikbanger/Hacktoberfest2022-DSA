#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll t;
cin>>t;
while(t--){
   ll n;
   cin>>n;
   ll a[n];
   for(ll i=0; i<n; i++){
    cin>>a[i];
   }
   sort(a,a+n);
   ll x=0,y=0;
   for(ll i=0; i<n; i++){
       x+=a[i];
       if(x>=n){
        break;
       }
       else{
          y++;
       }
   }
   cout<<y<<endl;
}
return 0;
}