//QUESTION: https://leetcode.com/problems/clone-graph/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp)
    {
        vector<Node*> adj;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        
        for(auto itr : node->neighbors)
        {
            if(mp.find(itr) != mp.end())
            {
                adj.push_back(mp[itr]);
            }
            else
            {
                adj.push_back(dfs(itr,mp));
            }
        }
        
        clone->neighbors = adj;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        
        unordered_map<Node*, Node*> mp;
        
        if(node ==  NULL)
        {
            return NULL;
        }
        
        if(node->neighbors.size() == 0)
        {
            Node* clone = new Node(node->val);
            return clone;
        }
        
        return dfs(node,mp);
    }
};
