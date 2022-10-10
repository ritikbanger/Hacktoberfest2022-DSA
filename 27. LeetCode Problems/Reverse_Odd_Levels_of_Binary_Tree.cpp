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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int>  level;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(q.size()){
            int sx = q.size();
            vector<int> lv;
            while(sx--){
                auto it = q.front();q.pop();
                lv.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(lvl & 1) reverse(lv.begin(), lv.end());
            
            for(auto i: lv) level.push_back(i);
            lvl++;
        }
        q.push(root);
        int i=0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto it = q.front(); q.pop();
                it->val = level[i++];
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }
       return root;
        
    }
};
