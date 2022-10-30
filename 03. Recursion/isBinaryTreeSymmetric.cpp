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
    bool lol( TreeNode *x,TreeNode *y){
        if(!x and !y ) return true;
        
        else if(!x or !y) return false;
        
        else if(x->val !=y->val) return false;
        
        return lol(x->left,y->right) and lol(x->right,y->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        
        return lol(root->left,root->right);
    }
};
