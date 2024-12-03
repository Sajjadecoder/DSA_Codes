#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};
Node *insertNode(Node *&root, int val)
{
    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    if (root->data > val)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }

    return root;
}
void inorder(Node *root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
    
}
bool searchInBST(Node *root,int target){
    if (root==NULL)
    {
        return false;
    }
    if (root->data==target)
    {
        return true;
    }
    if (root->data<target)
    {
        return searchInBST(root->right,target);
    }
    else{
        return searchInBST(root->left,target);
    }
    
    
}
Node* deleteNode(Node *root,int target){
    if (!root)
    {
        return NULL;

    }
    if (root->data>target)
    {
        root->left = deleteNode(root->left,target);
        return root;
    }else if (root->data<target)
    {
        root->right = deleteNode(root->right,target);
        return root;
    }else{
        //case1: leafnode deletion
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        // case 2: if 1 child exist(uska left exists)
        else if (root->right==NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // case 2: if 1 child exist(uska right exists)
        else if (root->left==NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
            
        }
        //case 3: if both children exist
        else{
        // step1: find greatest element from left   
        Node *child = root->left;
        Node *parent = root;
            while (child->right)
            {
                parent = child;
                child=  child->right;
            }
            if (root!=parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right= root->right;
                delete root;
                return child;
            }
            else{
                child->right = root->right;
                delete root;
                return child;
            }

        }
        
    }   
}
int main()
{
    int arr[6] = {3, 7, 4, 1, 6, 8};
    Node *root = NULL;
    for (int i = 0; i < 6; i++)
    {
        root = insertNode(root, arr[i]);
    }
    inorder(root);
    deleteNode(root,6);
    cout<<endl;
    inorder(root);
    
 
 
    return 0;
}