class Solution {
   
public:
    int ans;
    int kthSmallest(TreeNode* root, int &k) {
        if(root){
            kthSmallest(root->left,k);
            k--;
            if(k==0) ans=root->val;
            kthSmallest(root->right,k);
        }
        return ans;
    }
};
