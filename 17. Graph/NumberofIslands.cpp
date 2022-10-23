// Leetcode Medium Level

// Problem link : https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int i, int j, vector<vector<char>> &grid, int n, int m)
    {
        grid[i][j] = '2';
        for (int k = 0; k < 4; k++)
        {
            int nexti = i + dx[k];
            int nextj = j + dy[k];
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && grid[nexti][nextj] == '1')
            {
                dfs(nexti, nextj, grid, n, m);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
