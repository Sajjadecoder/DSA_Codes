#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
Node *createNode(int val){
    Node *newNode = new Node(val);
    return newNode;
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
void preorder(Node *root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right); 
    
}
void postorder(Node *root){
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right); 
    cout<<root->data<<" ";
    
}
void preorderStack(Node* root){
    if (root==NULL)
    {
        return;
    }
    stack <Node*> s;
    s.push(root);
    while (!s.empty())
    {
        Node *currentNode = s.top();
        s.pop();
        cout<<currentNode->data<<" ";
        if (currentNode->right)
        {
            s.push(currentNode->right);
        }
        if (currentNode->left)
        {
            s.push(currentNode->left);
        }
    }
    cout<<endl;
    
    
}
void postorderStack(Node* root){
    if (root==NULL)
    {
        return;
    }
    vector<int> v;
    stack <Node*> s;
    s.push(root);
    while (!s.empty() )
    {
     Node *currentNode = s.top();
        s.pop();
        v.push_back(currentNode->data);
        if (currentNode->left)
        {
            s.push(currentNode->left);
        }
        if (currentNode->right)
        {
            s.push(currentNode->right);
        }
    }
    reverse(v.begin(),v.end());
    int n = v.size();
   for (int i = 0; i < n; i++)
   {
    cout<<v[i]<<" ";
   }
   
    
    cout<<endl;
    
}
void inorderStack(Node *root ){
stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            curr = curr->left; 
        } 
  
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
        curr = curr->right; 
    }

    
}
void levelOrderTraversal(Node *root){
    queue<Node*> q;
    if (root==NULL)
    {
        return;
    }
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        
    }
    cout<<endl;   
    
}
int main(){
    Node *root = new Node(10);
    root->left = createNode(5);
    root->right = createNode(7);
    root->right->left = createNode(15);
    root->right->left->left = createNode(1);
    root->left->right = createNode(2);
    root->left->right->right = createNode(12);
    root->left->right->left = createNode(11);
    root->left->left= createNode(4);
    root->left->left->right= createNode(6);
    root->right->right = createNode(9);
    root->right->right->right = createNode(4);
    Node *temp = root;
    cout<<"PreOrder Traversal: ";
    temp = root;
    preorder(temp);
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    temp = root;
    postorder(temp);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    inorder(temp);
    cout<<endl;
    cout<<endl;
    cout<<"Pre order Traversal(without recursion): ";
    temp = root;
    preorderStack(temp);
    cout<<"post order Traversal(without recursion): ";
    temp = root;
    postorderStack(temp);
    cout<<"Inorder Traversal(without recursion): ";
    temp = root;
    inorderStack(temp);
    cout<<endl;
    cout<<"Level order Traversal(without recursion): ";
    temp = root;
    levelOrderTraversal(temp);
    cout<<endl;
 
    return 0;
}