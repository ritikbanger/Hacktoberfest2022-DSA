// Find the missing number in the array with the range till n
// Platform: LEETCODE

// ANSWER
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        for(int i=0;i<n;i++){
            sum-=nums[i];
        }
        return sum;
    }
};

// SOLUTION:
// 1. First we compute the total sum of the given in the given range
// 2. Then we find the sum of current array
// 3. In final step we subtract the total sum of array with the current sum of the array
