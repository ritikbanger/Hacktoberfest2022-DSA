// Problem Link : https://www.geeksforgeeks.org/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/

// Problem Statement : 
// Given a binary tree and a leaf node from this tree. It is known that in 1s all nodes connected to a given node (left child, right child, and parent)
// get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on. 
// The task is to find the minimum time required to burn the complete binary tree.

// Solution :-


class Solution {
  public:
    unordered_map<Node*, Node*> parent;
    Node* targetNode;
    
    void parentHelper(Node* root, int target, Node* par){
        
        if(!root)return;
        
        if(root -> data == target)targetNode = root;
        
        parent[root] = par;
        
        if(root -> left)parentHelper(root -> left, target, root);
        if(root -> right)parentHelper(root -> right, target, root);
        
    }
    
    int minTime(Node* root, int target) 
    {
      
      Node* par = new Node(-1);
      parentHelper(root, target, par);  
      
 
      queue<Node*> q;
      q.push(targetNode);
      int time = 0;
      unordered_map<Node*,int> vis;
      vis[targetNode]= 1;
      while(!q.empty()){
          int sz = q.size();
          bool burn = false;
          for(int i=0;i <sz; i++){
              auto node = q.front();
              q.pop();
              
              if(node -> left and !vis[node -> left]){
    
                  burn = true;
                  vis[node -> left] = 1;
                  q.push(node -> left);
              }
              if(node -> right and !vis[node -> right]){
                 
                  burn = true;
                  vis[node -> right] = 1;
                  q.push(node -> right);
              }
              if(parent[node] and parent[node]->data != -1 and !vis[parent[node]]){
                 
                  burn = true;
                  vis[parent[node]] = 1;
                   q.push(parent[node]);
              }
          }
          if(burn)time++;
      }
     
      return time;
        
   
    }
};


