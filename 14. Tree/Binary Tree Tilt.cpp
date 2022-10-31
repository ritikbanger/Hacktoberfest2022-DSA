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
    
    int tilt = 0;
    
    int sum(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int leftsum = sum(root->left);
        int rightsum = sum(root->right);
        
        int ltilt;
        
        ltilt = abs(leftsum - rightsum);
        
        tilt += ltilt;
        
        return (leftsum + rightsum + root->val);
    }
    
    int findTilt(TreeNode* root) {
        tilt = 0;
        
        sum(root);
        
        return tilt;
    }
};