// Question: NEXT PERMUTATION
//Platform: LEETCODE

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k,l;
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};

// EXPLANATION:

// 1. First we traverse over the given vector from the end (backwards).
// 2. While iterating we check for the element which is smaller than its next element (a[i]<a[i+1]), one we get the index satisfying our need we break the loop.
// 3. Again we traverse over the vector from the end (backward) till i, and find the element which is greater than our ith index value.
// 4. Once we find the element satifying our condition we store that index (k) and break.
// 5. We swap the values at ith index and kth index.
// 6. Our last step is to reverse the vector and we get our desired answer.
