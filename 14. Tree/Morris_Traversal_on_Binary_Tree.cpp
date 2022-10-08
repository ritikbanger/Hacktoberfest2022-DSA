#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    struct Node *left;
    struct Node *right;
};

void MorrisTraversal(struct Node *root)
{
    struct Node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{
    // Take dynamic input for binary tree.
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    struct Node *root = newNode(arr[0]);
    queue<struct Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n)
    {
        struct Node *temp = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            temp->left = newNode(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i >= n)
            break;

        if (arr[i] != -1)
        {
            temp->right = newNode(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    MorrisTraversal(root);

    return 0;
}
