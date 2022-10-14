
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    
    public: 
    
    void inOrder(Node* root,Node* &prev,Node* &head){
        if(root==NULL) return ;
        
        inOrder(root->left,prev,head);
        if(prev==NULL){
          prev=root;
          head=root;
        } 
        else{
            prev->right=root;
            root->left=prev;
            prev=root;
            
        }        
        
        
        inOrder(root->right,prev,head);
    }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return NULL;
        
        Node* prev = NULL;
        Node* head = NULL;  
        
        inOrder(root,prev,head);
        
        return head;
    }
};
