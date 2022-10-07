/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining. 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& ht) {
    int i = 0, j = ht.size() - 1, leftMax = 0, rightMax = 0, ans = 0;
    while ( i <= j) {
        if (ht[i] <= ht[j]) {
            if (ht[i] < leftMax) ans += leftMax - ht[i];
            else leftMax = ht[i];
            i++;
        }
        else {
            if (ht[j] < rightMax) ans += rightMax - ht[j];
            else rightMax = ht[j];
            j--;
        }
    } 
    return ans;
}

int main(){

    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(input);

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
