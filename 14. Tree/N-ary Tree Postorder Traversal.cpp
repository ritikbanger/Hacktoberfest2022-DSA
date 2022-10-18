// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void help(Node* root, vector<int> &ans) {
        if(!root) return;
        if(root->children.size())
            for(auto ch:root->children)
            help(ch, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        help(root, ans);
        return ans;
    }
};

/* 
Time: O(n)
Space: O(n)
    where n = no of nodes
*/
