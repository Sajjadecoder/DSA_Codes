#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data, height;
    Node *left;
    Node *right;
    Node(int val)
    {
        left = right = NULL;
        data = val;
        height = 1;
    }
};
int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}
int getBalance(Node *root)
{
    return (getHeight(root->left) - getHeight(root->right));
}

Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childleft = child->left;
    child->left = root;
    root->right = childleft;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insertNode(Node *root, int val)
{
    if (!root)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }
    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1) // left side unbalanced hai
    {

        if (val < root->left->data)
        {
            // left-left unbalanced
            return rightRotation(root);
        }
        else if (val > root->left->data)
        {
            // left-right unbalanced
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if (balance < -1) // right side unbalanced
    {
        if (val > root->right->data)
        {
            // right-right unbalanced
            return leftRotation(root);
        }
        else if (val < root->right->data)
        {
            // right-left unbalanced
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    return root;
}
Node *deleteNode(Node *root, int key)
{
    if (!root)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (!root->right && !root->left)
        {
            delete root;
            return NULL;
        }
        else if (root->right && !root->left) // right child exists
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right && root->left) // left child exists
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        { // both child exist
            Node *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        // update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        // check balance
        int balance = getBalance(root);
        if (balance > 1)
        // left side unbalanced
        {
            // Left Left
            if (getBalance(root->left) >= 0)
            {
                return rightRotation(root);
            }
            else
            {
                // Left Right
                root->left = leftRotation(root->left);
                return rightRotation(root);
            }
        }
        else if (balance < -1) // right side unbalanced
        {
            if (getBalance(root->right) <= 0) // Right right
            {
                return leftRotation(root);
            }
            else
            { // right-left
                root->right = rightRotation(root->right);
                return leftRotation(root);
            }
        }
        else{
            return root;
        }
    }
}
void traversal(Node *root)
{
    if (!root)
    {
        return;
    }
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}
int main()
{
    int arr[] = {10, 30, 20, 1, 3, 11, 14, 23};
    Node *root = NULL;
    for (int i = 0; i < 8; i++)
    {
        root = insertNode(root, arr[i]);
    }
    traversal(root);
    return 0;
}