#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
  int data;
	struct Node* left;
	struct Node* right;
};

void MorrisTraversal(struct Node* root)
{
	struct Node *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		}
		else {
			pre = current->left;
			while (pre->right != NULL
				&& pre->right != current)
				pre = pre->right;

			if (pre->right == NULL) {
				pre->right = current;
				current = current->left;
			}
			else {
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			} 
		} 
	} 
}

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{ 
  struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	MorrisTraversal(root);

	return 0;
}
