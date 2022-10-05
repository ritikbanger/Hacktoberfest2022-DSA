
#include <bits/stdc++.h>
using namespace std;
 

struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 

class bstit {
private:
    stack<node*> q;
 
public:
    bstit(node* root)
    {
        node* curr = root;
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }
 
    
    node* curr()
    {
        return q.top();
    }
 

    void next()
    {
        node* curr = q.top()->right;
        q.pop();
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }
 
    
    bool isEnd()
    {
        return !(q.size());
    }
};

void iterate(bstit it)
{
    while (!it.isEnd())
        cout << it.curr()->data << " ", it.next();
}
 
int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
 
    
    bstit it(root);
 
    
    iterate(it);
 
    return 0;
}