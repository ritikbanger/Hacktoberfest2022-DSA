 #include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define pb push_back
 #define vi vector<int>
 #define vl vector<ll>
 #define pii pair<int,int>
 #define pll pair<ll,ll>
 int static dp[1001][1001];
  int gcd(int a,int b)
 {
     if(b==0){return a;}
     else {return gcd(b,b%a);}
 }
 
//program for gcd of two number using dynamic programming
 int get_gcd(int a,int b){
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if(dp[a][b] != -1) return dp[a][b];
    if (a > b) dp[a][b] = gcd(a-b, b);
    else dp[a][b] = gcd(a, b-a);
    return dp[a][b];
 }
 int main()
 {
 ios_base::sync_with_stdio(false);
 /* cin.tie(NULL);
 cout.tie(NULL); */
 
  
     cout<<"Enter two num of which gcd you want to find\n";
     int x,y;
     cin>>x>>y;
     cout<<get_gcd(x,y);
  
 return 0;
 }
