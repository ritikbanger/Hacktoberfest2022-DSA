349. Intersection of Two Arrays
Easy

3746

2006

Add to List

Share
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
  ''' code '''
  class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        vector<int>ans;
        map<int,int>mp;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++)
        {
            s1.insert(nums1[i]);
        }
        for(int i=0;i<n2;i++)
        {
            s2.insert(nums2[i]);
        }
        for(auto it=s1.begin();it!=s1.end();it++)
        {
            mp[*it]++;
        }
        for(auto it=s2.begin();it!=s2.end();it++)
        {
            mp[*it]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==2)
            {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
