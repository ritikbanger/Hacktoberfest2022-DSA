/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(auto i:nums)
            mp[i]=target-i;
        int data,data2;
        vector<int> num=nums;
        sort(num.begin(),num.end());
        for(auto i:mp)
            if(binary_search(num.begin(),num.end(),i.second))
            {
                data=i.first;
                data2=i.second;
            }
        vector<int> ar;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==data)
                ar.push_back(i);
            else if(nums[i]==data2)
                ar.push_back(i);
        }
        return ar;
    }
};
