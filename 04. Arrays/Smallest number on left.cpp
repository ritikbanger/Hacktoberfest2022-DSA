/*
Question:
Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.


Example 1:
Input: n = 3
a = {1, 6, 2}
Output: -1 1 1
Explaination: There is no number at the 
left of 1. Smaller number than 6 and 2 is 1.


Example 2:
Input: n = 6
a = {1, 5, 0, 3, 4, 5}
Output: -1 1 -1 0 3 4
Explaination: Upto 3 it is easy to see 
the smaller numbers. But for 4 the smaller 
numbers are 1, 0 and 3. But among them 3 
is closest. Similary for 5 it is 4.


Your Task:
You do not need to read input or print anything. Your task is to complete the function leftSmaller() which takes n and a as input parameters and returns the list of smaller numbers.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 10000
0 ≤ a[i] ≤ 104  
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int> st;
        vector<int> v;
        for(int i=0; i<n; ++i){
            if(st.empty()) v.push_back(-1);
            else if(st.top()<a[i]){
                v.push_back(st.top());
            }
            else{
                while(!st.empty() && st.top()>=a[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(-1);
                else v.push_back(st.top());
            }
            
            st.push(a[i]);
        }
        return v;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
