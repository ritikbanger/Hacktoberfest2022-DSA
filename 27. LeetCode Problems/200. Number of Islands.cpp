
// Problem : https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    
    void checkIslands(vector<vector<char>>&grid,int i,int j,int m,int n){
        
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!='1'){
            return;
        }
        grid[i][j] = '2';
        checkIslands(grid,i-1,j,m,n);
        checkIslands(grid,i,j-1,m,n);
        checkIslands(grid,i+1,j,m,n);
        checkIslands(grid,i,j+1,m,n);

        
    }
    
    
    
    int countIslands(vector<vector<char>> &grid){
        
        int m = grid.size();
        int n = grid[0].size();
        int count  = 0;
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ;j < n ;j++){
                  if(grid[i][j]=='1'){
                      count++;
                      checkIslands(grid,i,j,m,n);
                  }        
            }
        }
        
        return count;
        
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        return countIslands(grid);
    }
};