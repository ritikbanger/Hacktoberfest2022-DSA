  vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int valueToFind;
        for(int i=0; i<nums.size(); i++){
            valueToFind=target-nums[i];
            if(mp.find(valueToFind)!=mp.end())
                return {i,mp[valueToFind]}; 
            mp.insert({nums[i],i});
        }
        return {};
    }
