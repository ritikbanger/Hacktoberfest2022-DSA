''' Q. You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only
one quantity of each item.In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[]such that sum of the weights of this subset is smaller
than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property). '''

# solution

class Solution:
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val, n):
        dp = [[0 for i in range(W+1)] for j in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,W+1):
                if i == 0 or j==0:
                    dp[i][j] = 0
                if wt[i-1]<= j:
                    dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]])
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][W]
                    
        # code here
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        W = int(input())
        val = list(map(int,input().strip().split()))
        wt = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.knapSack(W,wt,val,n))
