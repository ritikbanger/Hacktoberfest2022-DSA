// C++ program for arithmetic slices Problem

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        
        int n = nums.size();
        
        if(n <= 2)return 0;
        
        vector<int> dp(n);// dp[i] means the number of arithmetic slices ending with nums[i] 
        int ans = 0;
      
        for(int i=2; i<n ;i++){
        
             //if nums[i-2], nums[i-1], nums[i] are arithmetic, then the number of arithmetic slices ending with nums[i] (dp[i])
            // equals to:
            //      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // it is how dp[i] = dp[i-1] + 1 comes
              
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
            
                dp[i] = dp[i-1] + 1;
            }
        
            ans += dp[i];
        }
       
        
        return ans;
    }
};


int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin>> arr[i];
    }
    
    Solution obj;
    cout<< obj.numberOfArithmeticSlices(arr) << endl;

    return 0;
}
