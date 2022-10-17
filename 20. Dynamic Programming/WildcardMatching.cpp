// Link problem :  https://leetcode.com/problems/wildcard-matching/

    bool match(string&s, string&p, int i, int j, int m, int n, vector<vector<int>>&dp){
        
        if(i==m && j==n)
            return true;
        
        if(i==m){
            for(int t=j;t<n;t++)
            {
                if(p[t]!='*')
                    return false;
            }
            return true;
        }
        
        if(j==n && i!=m)
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(p[j]=='*')
            return dp[i][j]=match(s,p,i,j+1,m,n,dp) || match(s,p,i+1,j,m,n,dp);
        
        if(p[j]=='?' || s[i]==p[j])
            return dp[i][j]=match(s,p,i+1,j+1,m,n,dp);
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        
        return match(s,p,0,0,m,n,dp);
    }
