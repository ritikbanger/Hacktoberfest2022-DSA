/*
contributed by: Aazim Parwaz
Topic: postorder traversal- morris algorithm

*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int d) {
        val = d;
        left = NULL;
        right = NULL;
    }
};
void morris_traversal(TreeNode* root) {
    vector<int> ans;
    cout << "postorder traversal: ";
    if (!root)return;
    TreeNode* cur = root;
    while (cur) {

        if (!cur->right) {
            ans.push_back(cur->val);
            cur = cur->left;
        } else {
            TreeNode* temp = cur->right;

            while (temp->left && temp->left != cur) {
                temp = temp->left;
            }

            if (!temp->left) {
                temp->left = cur;
                ans.push_back(cur->val);
                cur = cur->right;
            } else if (temp->left == cur) {
                temp->left = NULL;
                // cout<<cur->val<<" ";
                cur = cur->left;

            }

        }


    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);



    morris_traversal(root);

    return 0;
}