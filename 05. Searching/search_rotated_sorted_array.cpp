// C++ Program to search an element
// in a sorted and pivoted array

#include<bits/stdc++.h>
using namespace std;

// Standard Binary Search function
int search(vector<int>& nums, int target) {
        
        int l = 0, h = nums.size()-1, mid;
        
        while(l<=h){
            
            mid = l+(h-l)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[l] <= nums[mid]){
                
                if(target >= nums[l] && target <= nums[mid])
                    h = mid -1;
                else
                    l = mid + 1;
                    
            }
            else{
                
                if (target >= nums[mid] && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            
        }
        return -1;
    }

// Driver program to check above functions
int main()
{
	int n;       //Size of the array
    cin>>n;

    vector<int> nums;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;

        nums.push_back(a);
    }

    int k;       //Element to be searched
    cin>>k;

    cout<<search(nums,k)<<endl;

	return 0;
}
