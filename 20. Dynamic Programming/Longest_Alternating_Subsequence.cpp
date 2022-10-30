int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		    int ma=1;
		    int mi=1;
		    for(int i=1;i<n;i++){
		        if(nums[i]>nums[i-1])
		        ma=mi+1;
		        else if(nums[i]<nums[i-1])
		        mi=ma+1;
		        else
		        continue;
		    }
		    return max(ma,mi);
	}	
