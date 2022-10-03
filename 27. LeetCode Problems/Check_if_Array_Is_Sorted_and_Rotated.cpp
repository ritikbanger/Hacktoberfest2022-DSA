/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/  
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i = 1; i<n; i++){
            if (nums[i-1] > nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0])
            count++;
        return count<=1;
        
    }
};
