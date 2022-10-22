// Problem Link : https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& a) 
    {
        int n = a.size();
        int i = 0;
        for(int num : a)
        {
            n ^= num; 
            n ^= i; 
            i++; 
        }
        return n; 
    }
};
