//MORRIS TRAVERSAL
//Time Complexity - O(N)
//Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;
//Tree Node
struct Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int x){
    data=x;
    left=NULL;
    right=NULL;
  }
};
//function defining Morris Traversal
void MorrisTraversal(Node* root){
  Node* curr;
  Node* prev;
  if(root==NULL)return ;
  
  curr=root;
  while(curr!=NULL){
    if(curr->left==NULL){
      cout<<curr->data<<" ";
      curr=curr->right;
    }
    else{
      prev=curr->left;
      while(prev->right!=NULL && prev->right!=curr){
        prev=prev->right;
      }
      if(prev->right==NULL){
        prev->right=curr;
        curr=curr->left;
      }  
      else{
        prev->right=NULL;
        cout<<curr->data<<" ";
        curr=curr->right;
      }  
    }  
  }  
}  
int main(){
  Node* root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->left->left=new Node(40);
  root->left->right=new Node(50);
  root->right->left=new Node(60);
  root->right->right=new Node(70);
  MorrisTraversal(root);
  return 0;
}
