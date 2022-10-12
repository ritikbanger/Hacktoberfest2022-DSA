//Increasing Triplet Subsequence leetcode solution

class Solution {
public:
 bool increasingTriplet(vector<int>& nums) {
          int z=INT_MAX;
          int q=INT_MAX;
     for(int i=0; i<nums.size(); i++)
     {
         if(z>=nums[i])
             z=nums[i];
         else if(q>=nums[i])
             q=nums[i];
         else
             return true;
     }   
         return false;
}
};
