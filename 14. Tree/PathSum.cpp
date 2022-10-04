// Question Link:: https://leetcode.com/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool calc(TreeNode* root, int t, int cur){
        
        if(root==NULL) return false;
        
        int va = root-> val;
        if(cur+ va==t && root->left==NULL && root->right==NULL) return true;
        
        bool ans= calc(root->left, t, cur+va) || calc(root->right,t, cur+va);
        
        return ans;
    }
    
    bool hasPathSum(TreeNode* root, int t) {
        
        bool ans = calc(root, t, 0);
        return ans;
    }
};
