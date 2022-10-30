//Link to the Problem - https://leetcode.com/problems/path-sum/
//Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// recursive solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)   return false;

        targetSum -= root->val;

        if(!root->left && !root->right && targetSum==0)  return true;

        bool left = false;
        if(root->left)
            left = hasPathSum(root->left, targetSum);

        bool right = false;
        if(root->right)
            right = hasPathSum(root->right, targetSum);

        return left|right;
    }
};
