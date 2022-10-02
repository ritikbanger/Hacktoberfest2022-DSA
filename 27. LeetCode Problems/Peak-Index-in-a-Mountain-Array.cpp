/* 
An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

 */


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s =0;
        int e = arr.size() -1 ;
        
        int mid = s + (e-s)/2;
        
        while(s<e){
            
            if(arr[mid]< arr[mid +1]){
                s= mid +1;
                
            }
            else{
                e = mid;
            }
            mid = s+ (e-s)/2;
        }
        return s;
    }
};
