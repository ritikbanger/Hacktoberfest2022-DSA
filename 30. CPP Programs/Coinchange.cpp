#include <bits/stdc++.h>
using namespace std;

int coinchange(int n, int v, int deno[])
			
{
    int dp[n+1][v+1];
    for(int i = 0;i<n+1;i++){
        for(int j=0;j<v+1;j++){
            dp[i][j]=-1;
        }
    }
	if (v == 0)
		return dp[n][v] = 1;
	if (n == 0)
		return 0;
	if (dp[n][v] != -1)
		return dp[n][v];
	if (deno[n - 1] <= v) {
		// Either Pick this coin or not
		return dp[n][v] = coinchange(n, v - deno[n - 1], deno)
						+ coinchange(n-1, v, deno);
	}
	else // We have no option but to leave this coin
		return dp[n][v] = coinchange(n-1, v, deno);
}
int main()
{
    int n;
    cin>>n;

    int v;
    cin>>v;
    int deno[n];
    for(int i = 0;i<n;i++){
        cin>>deno[i];
    } 
   
    
    
    cout<<coinchange(n,v,deno);
    

    return 0;
}
