// Question: INORDER TRAVERSAL OF BINARY TREE WITH 3 APPROACHES WITH EXPLANATION

// **MORRIS TRAVERSAL (based on threaded binary tree)**
// * Time Complexity: O(n)+O(n)
// * Space Complexity: O(1)

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
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
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
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
// 6. If the loop break means there can be 2 reason if root reaches the null at that time we make the connection by pointing prev to current.
// 7. else means our previous node pointer at current root, hence we break the connection, then storing the curr value then move it to left. (Left->Root->Right).


// **RECURSIVE SOLUTION**
// * Time Complexity: O(n)
// * Space Complexity: O(n)

class Solution {
private:

    void inorder(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }

};



// **EXPLANTION:**
// 1. As we know the inorder traversal moves (left->Root->right), so we are going to make the recursive calls in the same pattern.
// 2. The base case in recursive call is that when our root reaches the null we return.


// **ITERATIVE METHOD**
// * Time Complexity: O(n)
// * Space Complexity: O(n)
class Solution {
public:
    
vector<int> inorderTraversal(TreeNode* root) {
	vector<int>ans;
	stack<TreeNode*>st;        
	while(root || !st.empty()){
		while(root){
			st.push(root);
			root=root->left;                
		}
		root=st.top();
		st.pop();
		ans.push_back(root->val);
		root=root->right;
	}
	return ans;        
}
    
};

// **EXPLANATION:**
// 1. First we make the stack to store the every root in our stack and moving root to left till root reaches the NULL.
// 2. When root reaches the null we pop the top element in our stack and store that value in answer vector and moving root to root's right.
