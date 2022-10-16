/*You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.*/


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        vector<int> u;
        vector<int> b;
        vector<int> d;
        int size=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK)
                u.push_back(i);
        }
        u.push_back(size);        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxK)
                b.push_back(i);
        }
        b.push_back(size);        
        for(int i=0;i<nums.size();i++){        
            if(nums[i]<minK || nums[i]>maxK)
                d.push_back(i);
        }
        d.push_back(size);
        long long int j=0;
        for(int i=0;i<size;i++){
            int x = *lower_bound(d.begin(),d.end(),i);
            int  y = *lower_bound(u.begin(),u.end(),i);
            int z = *lower_bound(b.begin(),b.end(),i);
            int c = max(y,z);
            int d=0;
            if(c<x){
                d = x-c;
            }
            j = j+d;
        }
        return j;
        
    }
};
