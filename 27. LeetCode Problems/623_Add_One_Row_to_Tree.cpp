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
    void helper(TreeNode* r, int val, int dep, int lev) {
        if(!r) return;
        if(lev == dep - 1) {
            TreeNode *t1 = r->left;
            r->left = new TreeNode(val);
            r->left->left = t1;
            TreeNode *t2 = r->right;
            r->right = new TreeNode(val);
            r->right->right = t2;
            return;
        }
        if(r->left)
            helper(r->left, val, dep, lev + 1);
        if(r->right)
            helper(r->right, val, dep, lev + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *t = new TreeNode(val);
            t->left = root;
            root = t;
            return root;
        }
        helper(root, val, depth, 1);
        return root;
    }
};