#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MX = 1e6 + 7;
const ll p = 5; 
const ll m = 1e9 + 7;

vector<long long> p_pow(MX); 
vector<long long> pre(MX), suff(MX); 

void rabin_karp(string s) {
    ll S = s.size();

    pre[0] = suff[0] = 0;
    for (ll i = 0; i < S; i++)
      pre[i+1] = (pre[i] + (s[i] - '0' + 1) * p_pow[i]) % m; 

    reverse(s.begin(), s.end());
    for (ll i = 0; i < S; i++)
      suff[i+1] = (suff[i] + (s[i] - '0' + 1) * p_pow[i]) % m; 
}

bool isPoss(ll n, ll len) {
  ll h1, h2, h3, h4;
  h1 = (p_pow[n - len]*pre[len]) % m;
  h2 = (suff[n] + m - suff[n - len]) % m;

  h3 = (pre[n] + m - pre[len]) % m;
  h4 = (p_pow[len]*suff[n - len]) % m;

  return((len != 1 && h1 != h2) && (n - len != 1 && h3 != h4));
}

bool isPalin(string& s) {
  for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
    if(s[i] != s[j])
      return 0;
  }

  return 1;
}

void solve() {
  ll n;
  string s;
  cin >> n >> s;
  n *=2;
  rabin_karp(s);

  if(!isPalin(s)) {
    cout << "1\n" << n << '\n';
    return;
  }

  for(ll len = 1; len < n; len++) {
    if(isPoss(n, len)) {
      cout << "2\n" << len << " " << n-len << '\n';
      return;
    }
  }

  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  p_pow[0] = 1; 
  for (ll i = 1; i < (ll)p_pow.size(); i++) 
      p_pow[i] = (p_pow[i-1] * p) % m;

  int t;
  cin >> t;
  while(t--) {
      solve();
  }
}