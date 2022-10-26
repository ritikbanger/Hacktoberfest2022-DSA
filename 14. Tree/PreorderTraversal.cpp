// Question: PREORDER TRAVERSAL OF BINARY TREE WITH 3 APPROACHES


// **MORRIS TRAVERSAL (based on threaded binary tree)**
// * Time Complexity: O(n)+O(n)
// * Space Complexity: O(1)

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;        
    }

};

// **EXPLANATION:**
// 1. The main thing we going to do in this is to make the tree left's right threaded.
// 2. First we make the curr root to store the root of tree to avoid the lost of root.
// 3. Then we run the loop till our current root does not reaches the null.
// 4. In loop we first check if the current left is left or not if yes then we store the current value in answer vector and move current to current's right.
// 5. If left is present then we move further, then we make the another node prev which is going to iterate over the right nodes of current root.
// 6. If the loop break means there can be 2 reason if root reaches the null at that time we make the connection by pointing prev to current after making connection then store the curr value then move.
// 7. else means our previous node pointer at current root, hence we break the connection, it to left. (Root->Left->Right).


// **RECURSIVE SOLUTION**
// * Time Complexity: O(n)
// * Space Complexity: O(n)

class Solution {
private:

    void preorder(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;        
    }

};
```


// **EXPLANTION:**
// 1. As we know the inorder traversal moves (Root->Left->right), so we are going to make the recursive calls in the same pattern.
// 2. The base case in recursive call is that when our root reaches the null we return.


// **ITERATIVE SOLUTION**
// * Time Complexity: O(n)
// * Space Complexity: O(n)

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        while(root || !st.empty()){
            if(root){
                ans.push_back(root->val);                
                if(root->right){
                    st.push(root->right);
                }
                root=root->left;
            }
            else{
                root=st.top();
                st.pop();
            }
        }
        return ans;
    }
    
};

// EXPLANATION:
// 1. First we make the stack to store the every root in our stack and storing the if root rights if present and move to the root's left.
// 2. When root reaches the null we pop the top element in our stack.
