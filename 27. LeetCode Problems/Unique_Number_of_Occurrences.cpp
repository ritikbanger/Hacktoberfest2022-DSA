/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> mp;
        for(int x : arr){
            mp[x] += 1;
        }
        set<int>st;
        for(auto it: mp){
            if(st.count(it.second)>0)
                return false;
            else st.insert(it.second);
        }
        return true;
        
    }
};
