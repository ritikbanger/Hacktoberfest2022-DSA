string longest_palindromic_substring(const string & s){
    const int m = s.length();
    if(m<2)
        return s;
    string s2 = "#";
    for(int i = 0; i < m; i++)
        s2.push_back(s[i]), s2.push_back('#');
                    
    int cx = 0, mx = 0;
    const int m2 = 2*m+1;
    vector<int> dp(m2,0);
    
    for(int i = 1; i < m2; i++){
        int j = 0;
        if(i>=mx)
            j = i+1;            
        else{
            int ii = 2*cx-i;
            dp[i] = min(mx-i,dp[ii]);
            if(ii-dp[ii]<=cx-dp[cx])
                j = mx+1;                
        }

        while(j&&(j<m2)&&(2*i-j>=0)&&(s2[j]==s2[2*i-j]))
            dp[i]++, j++;
        
        if(i+dp[i]>mx)
            mx = i+dp[i], cx = i;
    }        
    
    int maxlength = 0;
    int id = 0;
    for(int i = 1; i < m2; i++)
        if(dp[i]>maxlength){
            maxlength = dp[i];
            id = i;
        }
            
    string res;
    for(int j = id-dp[id]+1; j <= id+dp[id]; j+=2)
        res.push_back(s2[j]);

    return res;
}
