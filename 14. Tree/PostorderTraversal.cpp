// Question: POSTORDER TRAVERSAL WITH 2 APPROACHES WITH EXPLANATION

// **RECURSIVE SOLUTION**
// * Time Complexity: O(n)
// * Space Complexity: O(n)


class Solution {
private:
    void postOrder(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int>ans;
        postOrder(root,ans);
        return ans;
    }
};


// **EXPLANTION:**
// 1. As we know the postorder traversal moves (Left->right->Root), so we are going to make the recursive calls in the same pattern.
// 2. The base case in recursive call is that when our root reaches the null we return.


// **ITERATIVE SOLUTION**
// * Time Complexity: O(n)
// * Space Complexity: O(n)


class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        return ans;
    }

};
