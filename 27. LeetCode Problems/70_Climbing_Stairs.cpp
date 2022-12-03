class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return find(n);
    }
    int find(int n) {
        if(n <= 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int one = find(n - 1);
        int two = find(n - 2);
        return dp[n] = one + two;
    }
};