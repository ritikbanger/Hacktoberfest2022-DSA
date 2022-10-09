// problem link: https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int n;
    int dp[20001];
    int solve(int id, vector<int>& nums)
    {
        if(id>=n) return 0;
        if(dp[id]!=-1) return dp[id];
        int curel=nums[id];
        int cursum=nums[id];
        int i=id+1;
        
        while(i<n && nums[i]==curel)
        {
            cursum+=nums[i];i++;
        }
        
        while(i<n && nums[i]==curel+1)
        {
            i++;
        }
        
        return dp[id]=max(cursum+solve(i,nums),solve(id+1,nums));
        
    }
    int deleteAndEarn(vector<int>& nums) 
    {
         n=nums.size();
        sort(nums.begin(), nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
    
};