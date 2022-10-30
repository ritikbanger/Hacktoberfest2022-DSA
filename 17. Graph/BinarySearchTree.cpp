#include <iostream>

using namespace std;

template <class T>

/**
 * A simple BST Node
 * that will contain
 * --> Data
 * --> left child
 * --> right child
 */
class Node
{
public:
    T data;
    Node *lChild;
    Node *rChild;
};
template <class T>

/**
 * Implementing the structure of
 * a BST
 * using BST nodes
 */

class BST
{

public:
    Node<T> *root = new Node<T>();
    Node<T> *loc = new Node<T>();
    Node<T> *preloc = new Node<T>();

    int leadNodes = 0;
    int nodes_withLChild = 0;
    int nodes_withRChild = 0;
    int nodes_withTwoChild = 0;

    BST()
    {
        root = NULL;
        loc = NULL;
        preloc = NULL;
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    /**
     * In case of making a tree with a no duplicate node
     * we have to first search weather the specific data
     * already exists in the tree or not
     */
    void search(T value)
    {
        loc = root;
        preloc = NULL;

        while (loc != NULL && loc->data != value)
        {
            if (value < loc->data)
            {
                preloc = loc;
                loc = loc->lChild;
            }
            else
            {
                preloc = loc;
                loc = loc->rChild;
            }
        }
    }

    void insertWithoutDuplication(T value)
    {
        // cout << "Adding value: " << value << endl;
        search(value);

        // if value not found and loc reaches end point
        if (loc == NULL)
        {
            Node<T> *newnode = new Node<T>();
            newnode->data = value;

            if (preloc != NULL)
            {
                if (value < preloc->data)
                    preloc->lChild = newnode;
                else
                    preloc->rChild = newnode;
            }
            else
                root = newnode;
        }
        // if loc founds the duplicate value
        else
            cout << "Duplicate values are not allowed!" << endl;
    }

    /**
     * Finding the logical position of the node
     * then adding the newnode.
     * --> In this case the duplicate node will be
     * considered as a smaller node and will be
     * added on the left handside
     */
    void insertionWithDuplication(T value)
    {

        Node<T> *newnode = new Node<T>();
        newnode->data = value;

        if (!isEmpty())
        {
            loc = root;
            preloc = NULL;

            while (loc != NULL)
            {
                if (value <= loc->data)
                {
                    preloc = loc;
                    loc = loc->lChild;
                }
                else
                {
                    preloc = loc;
                    loc = loc->rChild;
                }
            }

            if (value <= preloc->data)
            {
                preloc->lChild = newnode;
            }
            else
            {
                preloc->rChild = newnode;
            }
        }
        else
            root = newnode;
    }

    /**
     * We just have to find the left most node
     * as we know that
     * --> left most node is the smalled value of
     * a binary search tree
     */
    void smallestValue()
    {
        if (!isEmpty())
        {
            loc = root;
            preloc = NULL;

            while (loc->lChild != NULL)
            {
                loc = loc->lChild;
            }
            cout << "🤏 Smallest value: " << loc->data << endl;
        }
        else
            cout << "Your Tree is Empty!" << endl;
    }

    /**
     * We just have to find the right most node
     * as we know that
     * --> right most node is the largest value of
     * a binary search tree
     */
    void largestValue()
    {
        if (!isEmpty())
        {
            loc = root;
            preloc = NULL;

            while (loc->rChild != NULL)
            {
                loc = loc->rChild;
            }
            cout << "🤪 Largest value: " << loc->data << endl;
        }
        else
            cout << "Your Tree is Empty!" << endl;
    }

    /**
     * We have calculated the height on the basis of
     * --> 1 + Max(height of x’s left subtree, height of x’s right sub-tree)
     * --> We decremented (-1) in case of a empty tree
     * --> We increment (+1) in case of a not null tree
     * --> height of a Leaf Node will be "0"
     */
    int heightofNode(Node<T> *node)
    {
        if (node)
        {
            int lh = heightofNode(node->lChild);
            int rh = heightofNode(node->rChild);

            if (lh > rh)
                return lh + 1;
            else
                return rh + 1;
        }
        else
        {
            return -1;
        }
    }

    /**
     * We know depth of root is "0". S0,
     * --> Depth of a node x in a binary tree is
     *  1 plus the depth of its parent node
     */
    int depthofNode(Node<T> *node, int depth)
    {
        if (node)
        {
            int ld = depthofNode(node->lChild, depth + 1);
            int rd = depthofNode(node->rChild, depth + 1);

            if (ld > rd)
                return ld + 1;
            else
                return rd + 1;
        }
        else
        {
            return -1;
        }
    }

    /**
     * We can use the following tranversal
     * methods to print the nodes in a respective
     * way
     */
    void inorder(Node<T> *treeNode)
    {
        if (treeNode != NULL)
        {
            inorder(treeNode->lChild);
            cout << treeNode->data << "  ";
            inorder(treeNode->rChild);
        }
    }

    void postOrder(Node<T> *treeNode)
    {
        if (treeNode != NULL)
        {
            postOrder(treeNode->lChild);
            postOrder(treeNode->rChild);
            cout << treeNode->data << "  ";
        }
    }

    void preOrder(Node<T> *treeNode)
    {
        if (treeNode != NULL)
        {
            cout << treeNode->data << "  ";
            preOrder(treeNode->lChild);
            preOrder(treeNode->rChild);
        }
    }

    void inorder()
    {
        if (root != NULL)
            inorder(root);
        else
            cout << "Tree is Empty!" << endl;
    }

    void preOrder()
    {
        if (root != NULL)
            preOrder(root);
        else
            cout << "Tree is Empty!" << endl;
    }

    void postOrder()
    {
        if (root != NULL)
            postOrder(root);
        else
            cout << "Tree is Empty!" << endl;
    }

    /**
     * Now making methods for the deletion of a
     * specific node of a binary search tree
     */
    void deleteNode(T value)
    {

        search(value);
        // LOC is the node to be deleted
        // PLOC will be its parent node

        if (loc == NULL)
        {
            cout << "This value don't exists!" << endl;
        }

        // CASE 1 --> DELETE A LEAF NODE
        else if (loc->lChild == NULL && loc->rChild == NULL)
            delLeafNode();

        // CASE 2 --> DELETING NODE WITH A CHILD
        else if (loc->lChild != NULL && loc->rChild == NULL)
            del_withLChild();

        else if (loc->lChild == NULL && loc->rChild != NULL)
            del_withRChild();

        // CASE 3 --> DELETING NODE WITH TWO CHILDRENS
        else if (loc->lChild != NULL && loc->rChild != NULL)
            del_withChilds();
    }

    void delLeafNode()
    {
        if (preloc == NULL)
        {
            root = NULL;
        }
        else if (preloc->lChild == loc)
        {
            preloc->lChild = NULL;
        }
        else
        {
            preloc->rChild = NULL;
        }
        delete loc;
    }

    void del_withLChild()
    {
        if (preloc == NULL)
        {
            root = loc->lChild;
        }
        else if (preloc->lChild == loc)
        {
            preloc->lChild = loc->lChild;
        }
        else
        {
            preloc->rChild = loc->lChild;
        }
        delete loc;
    }

    void del_withRChild()
    {
        if (preloc == NULL)
        {
            root = loc->rChild;
        }
        else if (preloc->lChild == loc)
        {
            preloc->lChild = loc->rChild;
        }
        else
        {
            preloc->rChild = loc->rChild;
        }
        delete loc;
    }

    /**
     * Finding the replacement node
     * --> logical predecessor
     * --> It will be the rightmost value
     *     in the left subtree of the
     *     Loc (node to be deleted)
     * --> loc1 and ploc1 will help us
     *     in finding this right most value
     */
    void del_withChilds()
    {

        Node<T> *ploc1 = loc;
        Node<T> *loc1 = loc->lChild; // as logical PD will be in left subtree

        // finding the right most value as predecessor
        // loc1 ---> will be the Replacement Node (RPN)
        while (loc1->rChild != NULL)
        {
            ploc1 = loc1;
            loc1 = loc1->rChild;
        }

        // if lchild of loc itself the rpn
        if (loc->lChild == loc1)
            loc->lChild = loc1->lChild;
        // if rpn have left child
        else if (loc1->lChild != NULL)
            ploc1->rChild = loc1->lChild;
        else
            ploc1->rChild = NULL;

        // now replacing RPN with node to be deleted
        loc1->lChild = loc->lChild;
        loc1->rChild = loc->rChild;

        // updating the Parent root
        if (preloc == NULL) // if node to be deleted is a root
            root = loc1;
        else if (preloc->lChild == loc)
            preloc->lChild = loc1;
        else
            preloc->rChild = loc1;

        delete loc;
    }

    void destroyTree(Node<T> *treeNode)
    {
        if (treeNode != NULL)
        {
            destroyTree(treeNode->lChild);
            destroyTree(treeNode->rChild);
            delete treeNode;
        }
    }

    void destroyTree()
    {
        destroyTree(root);
        root = NULL;
    }

    void printLeafNodes(Node<T> *treeNode)
    {
        if (treeNode)
        {
            printLeafNodes(treeNode->lChild);
            printLeafNodes(treeNode->rChild);
            if (treeNode->lChild == NULL && treeNode->rChild == NULL)
                cout << treeNode->data << "  ";
        }
    }

    void printLeafNodes()
    {
        if (root)
            printLeafNodes(root);
        else
            cout << "Tree is Empty!" << endl;
    }

    /**
     * if a leaf node founds we will delete that node
     * and will return
     */
    void deleteLeafNodes(Node<T> *treeNode)
    {
        if (treeNode)
        {
            if (treeNode->lChild == NULL && treeNode->rChild == NULL)
            {
                deleteNode(treeNode->data);
                return;
            }
            deleteLeafNodes(treeNode->lChild);
            deleteLeafNodes(treeNode->rChild);
        }
    }

    void deleteLeafNodes()
    {
        if (root)
            deleteLeafNodes(root);
        else
            cout << "Tree is Empty!" << endl;
    }

    /**
     * Deleting only those nodes that have
     * only left subree(lchild)
     */

    void deleteNodes_withLeftSubtree(Node<T> *treeNode)
    {
        if (treeNode)
        {
            if (treeNode->lChild != NULL && treeNode->rChild == NULL)
            {
                deleteNode(treeNode->data);
                return;
            }
            deleteNodes_withLeftSubtree(treeNode->lChild);
            deleteNodes_withLeftSubtree(treeNode->rChild);
        }
    }

    void deleteNodes_withLeftSubtree()
    {
        if (root)
            deleteNodes_withLeftSubtree(root);
        else
            cout << "Tree is Empty!" << endl;
    }

    void countNodes(Node<T> *treeNode)
    {
        if (treeNode)
        {
            countNodes(treeNode->lChild);
            countNodes(treeNode->rChild);
            if (treeNode->lChild == NULL && treeNode->rChild == NULL)
                leadNodes++;
            if (treeNode->lChild != NULL && treeNode->rChild == NULL)
                nodes_withLChild++;
            if (treeNode->lChild == NULL && treeNode->rChild != NULL)
                nodes_withRChild++;
            if (treeNode->lChild != NULL && treeNode->rChild != NULL)
                nodes_withTwoChild++;
        }
    }

    void countNodes()
    {
        leadNodes = nodes_withTwoChild = nodes_withRChild = nodes_withLChild = 0;
        if (root)
            countNodes(root);
        else
            cout << "Tree is Empty!" << endl;

        cout << "Leaf Nodes : " << leadNodes << endl;
        cout << "Nodes with only Left Child : " << nodes_withLChild << endl;
        cout << "Nodes with only Right Child : " << nodes_withRChild << endl;
        cout << "Nodes with both Children : " << nodes_withTwoChild << endl;
    }
};

int main()
{
    BST<int> *tree = new BST<int>();

    // tree->insertWithoutDuplication(2);
    tree->insertWithoutDuplication(5);
    tree->insertWithoutDuplication(3);
    tree->insertWithoutDuplication(9);
    tree->insertWithoutDuplication(7);
    tree->insertWithoutDuplication(12);
    tree->insertWithoutDuplication(6);
    tree->insertWithoutDuplication(8);

    cout << "\n"
         << endl;
    cout << "Printing Nodes: ";
    tree->inorder();
    cout << endl;

    // LARGEST & SMALLEST VALUES
    tree->smallestValue();
    tree->largestValue();

    // HEIGHT & DEPTHS
    cout << "📏 Height of BST: " << tree->heightofNode(tree->root) << endl;
    cout << "📏 Depth of BST: " << tree->depthofNode(tree->root, 0) << endl;

    cout << "\n"
         << endl;
    // TRANVERSE ORDERS
    cout << "Printing Nodes: ";
    tree->inorder();
    cout << endl;

    cout << "❌ Deleting 9" << endl;
    tree->deleteNode(9);

    // cout << "Destroying the TREE!" << endl;
    // tree->destroyTree();

    cout << "Printing Leaf Nodes: ";
    tree->printLeafNodes();
    cout << endl;

    cout << "❌ Deleting Leaf Nodes " << endl;
    tree->deleteLeafNodes();

    cout << "❌ Deleting Nodes only have a left Subtree!" << endl;
    tree->deleteNodes_withLeftSubtree();

    cout << "Printing Nodes: ";
    tree->inorder();
    cout << endl;

    tree->countNodes();

    // tree->preOrder(tree->root);
    // cout << endl;
    // tree->postOrder(tree->root);
    // cout << endl;
    // tree->deleteNode(9);
}
