// Hacktoberfest2022 Contribution
//problem number on leetcode - 2433
//https://leetcode.com/contest/weekly-contest-314/problems/find-the-original-array-of-prefix-xor/
//Problem Statement
/*You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
Note that ^ denotes the bitwise-xor operation.

It can be proven that the answer is unique.*/
//example :
/*Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.*/
//Solution :
//Approach : 
//in XOR operation we know that if x=a^b  ans y=a then x^y=b
//conclusion is that , repeating numbers will be discarded and different one will remain.
//so in given array we have pref[4]=xor of 0 to 4 index numbers
//                   and in pref[3]=xor of 0 to 3 index numbers
//                     so  pref[4]^pref[3]=element at 4th index

//Code :
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size(),0);
        int n=pref.size();
        for(int i=n-1;i>0;i--){
            ans[i]=pref[i]^pref[i-1];
        }
        ans[0]=pref[0];
        return ans;
    }
};
