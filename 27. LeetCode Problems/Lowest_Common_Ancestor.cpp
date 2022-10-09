// Find the Lowest Common Ancestor of two given nodes in a Binary Tree:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root; // if root is NULL or if found the node to search        
        
        // recursive search:
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        // if both NULL, did not find required node:        
        if (l == NULL && r == NULL) return NULL;
        
        // if any one null, found the other node:
        if (l == NULL || r == NULL)
        {
            if (l == NULL) return r;
            else return l;
        }
        return root;        
    }
};
