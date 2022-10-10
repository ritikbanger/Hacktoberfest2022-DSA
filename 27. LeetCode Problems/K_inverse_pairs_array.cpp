//contributor: ChakitBhandari
  Solution(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
  }
  const int M=1e9 + 7;
  #define ll long long
  int kInversePairs(int n, int k) {
      int dp[n+1][k+1];
      for(int i=0;i<=n;++i){
          for(int j=0;j<=k;++j){
              if(j == 0)
                  dp[i][j] = 1;
              else if(i == 0)
                  dp[i][j] = 0;
              else if(j < i)
                  dp[i][j] = ((ll)dp[i-1][j]%M + dp[i][j-1]%M)%M;
              else
                  dp[i][j] = ((ll)dp[i-1][j]%M + dp[i][j-1]%M - dp[i-1][j-i]%M + M)%M;
          }
      }

      return dp[n][k];
  }
