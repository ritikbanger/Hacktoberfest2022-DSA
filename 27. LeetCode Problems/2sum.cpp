class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(m[target-nums[i]]!=0)
            {
                v = {i,m[target-nums[i]]-1};
                break;
            }
            else m[nums[i]] = i+1;
        }
        return v;
    }
};