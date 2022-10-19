#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename t>
class treenode
{
public:
    t data;
    vector<treenode<t> *> children;
    treenode(t data)
    {
        this->data = data;
    }
    ~treenode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
treenode<int> *takeinput()
{
    int data;
    cout << "enter the root data" << endl;
    cin >> data;
    treenode<int> *root = new treenode<int>(data);
    queue<treenode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        treenode<int> *front = q.front();
        q.pop();
        int x;
        cout << "how many child of" << front->data << endl;
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            cout << "enter the data of " << i << "th child" << endl;
            cin >> data;
            treenode<int> *child = new treenode<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}
int greateer(treenode<int> *root, int k)
{
    int x = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->data > k)
    {
        x++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        treenode<int>*child=root->children[i];
       x=x+ greateer(child, k);
        
    }
    return x;
}
int main()
{
    treenode<int> *root = takeinput();
    cout << greateer(root, 10);
}