// Leetcode 1861: Rotating the Box
// https://leetcode.com/problems/rotating-the-box/

class Solution {
public:        

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
            int m = box.size(), n = box[0].size();
            vector<vector<char>> res(n, vector<char>(m, '.'));
            for (int i = 0; i < m; ++i)
                for (int j = n - 1, k = n - 1; j >= 0; --j)
                    if (box[i][j] != '.') {
                        k = box[i][j] == '*' ? j : k;
                        res[k--][m - i - 1] = box[i][j];
                    }

            return res;
        
    }
};