class Solution {
public:    
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        vector<int> prev(m+1, -1), curr(m+1, -1);
        
        // for(int i = 0; i <= n; i++) dp[i][0] = i; //Covered in the nested for
        for(int j = 0; j <= m; j++) prev[j] = j;
        
        for(int i = 1; i<=n; i++){
            curr[0] = i;
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 0 + prev[j-1] ;
                else{
                    curr[j] = 1 + min(prev[j], //delete
                                    min(curr[j-1], //insert
                                        prev[j-1])); //replace
                }
            }
            prev = curr;
        }
        
        return prev[m];
    }
};
