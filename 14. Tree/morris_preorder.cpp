
/*
contributed by: Aazim Parwaz
Topic: preorder traversal- morris algorithm

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
    cout << "preorder traversal: ";
    if (!root)return;
    TreeNode* cur = root;
    while (cur) {

        if (!cur->left) {
            cout << cur->val << " ";
            cur = cur->right;
        } else {
            TreeNode* temp = cur->left;

            while (temp->right && temp->right != cur) {
                temp = temp->right;
            }

            if (!temp->right) {
                temp->right = cur;
                cout << cur->val << " ";
                cur = cur->left;
            } else if (temp->right == cur) {
                temp->right = NULL;
                // cout<<cur->val<<" ";
                cur = cur->right;

            }

        }


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