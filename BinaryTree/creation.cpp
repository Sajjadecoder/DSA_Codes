#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
};  
Node* buildTree(Node *root)
    {
        cout <<"Enter val: ";
        int val;
        cin>>val;
        root = new Node(val)
        ;
        if (val==-1)
        {
            return NULL;
        }
        cout<<"Enter data for inserting in left of "<<val<<": "<<endl;
        root->left = buildTree(root->left);
        cout<<"Enter data for inserting in right of "<<val<<": "<<endl;
        root->right = buildTree(root->right);
        return root;
    }
void inOrder(Node* root){
    if (root==NULL)
    {
        return;

    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

    
}
void preOrder(Node* root){
    if (root==NULL)
    {
        return;

    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root){
    if (root==NULL)
    {
        return;

    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node *root = NULL;
    
    root = buildTree(root);
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
}