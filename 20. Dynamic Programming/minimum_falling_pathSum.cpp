/* 
* Minimum Falling Path Sum - Dynamic Programming
* Problem Description:
* Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
*
* A falling path starts at any element in the first row and chooses the element in the next row that is
* either directly below or diagonally left/right. Specifically, the next element from position (row, col) 
* will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*
* Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
* Output: 13
*/

#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int ans = 1e8, n = matrix.size();

    vector<int> prev(n, 0);
    vector<int> curr(n, 0);
    
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(i == n-1){
                curr[j] = matrix[i][j];
            }
            else{
                int option2 = 1e8, option3 = 1e8;
                int option1 = matrix[i][j] + prev[j];
                if(j-1>=0)
                    option2 = matrix[i][j] + prev[j-1];
                if(j+1<=n-1)
                    option3 = matrix[i][j] + prev[j+1];

                curr[j] = min(option1, min(option2, option3));
            }
        }
        prev = curr;
    }
    
    
    for(int j=0; j<matrix.size(); j++){
        ans = min(ans, curr[j]);
    }
    
    return ans;
}

int main() {
    vector<vector<int> > matrix{{2, 1, 3},
                                {6, 5, 4},
                                {7, 8, 9}};  
    cout<<minFallingPathSum(matrix);

    return 0;
}