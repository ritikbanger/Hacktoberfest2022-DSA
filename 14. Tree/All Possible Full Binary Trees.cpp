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
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        vector<TreeNode*> trees;
        
        if(n == 1)
        {
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        
        for(int i = 2; i < n; i++)
        {
            vector <TreeNode*> leftSubtrees = allPossibleFBT(i-1);
            vector <TreeNode*> rightSubtrees = allPossibleFBT(n-i);
            
            for(int j = 0; j < leftSubtrees.size(); j++)
            {
                TreeNode* left = leftSubtrees[j];
                
                for(int k = 0; k < rightSubtrees.size(); k++)
                {
                    TreeNode* right = rightSubtrees[k];
                    
                    TreeNode* node = new TreeNode(0);
                    node->left = left;
                    node->right = right;
                    
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }
};