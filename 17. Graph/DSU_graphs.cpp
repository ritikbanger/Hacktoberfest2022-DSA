#include<bits/stdc++.h>
using namespace std;
#define HareKrishna ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define mod 1000000007
#define ll long long int
#define pb push_back
const ll N=1e6;

ll components=0;
ll cur_ans=1;

struct dsu {
    vector<ll> par;
    vector<ll> sze;
 
    void make_set(ll n) {
        par.resize(n + 1);
        sze.assign(n + 1, 1);
        iota(par.begin(),par.end(), 0);
    }
 
    int get(int x) {
        return (par[x] = (par[x] == x ? x : get(par[x])));
    }
 
    void un(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (sze[x] > sze[y]) {
            swap(x, y);
        }
        components--;
        sze[y] += sze[x];
        par[x] = y;
        cur_ans = max(cur_ans, max(sze[x], sze[y]));
    }
};

void rk_d(){
  ll n,m;
  cin>>n>>m;
  ll i;
  
  components=n;
  dsu x;
  x.make_set(n);
  
  while (m--){
    ll u,v;
    cin>>u>>v;
    
    x.un(u,v);
    cout<<components<<" "<<cur_ans<<endl;
  }
  
}

int main(){
	
   HareKrishna;
   ll t;
  // cin>>t;
    t=1;
   
   while (t--){
   	
   	rk_d();
   	
   }
   
   return 0;
}

