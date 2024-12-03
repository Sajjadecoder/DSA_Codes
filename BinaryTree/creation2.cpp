#include<iostream>
#include<queue>
#include<string>
#include <stack>
#include<vector>

using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left=right=NULL;
    }



};
void print(string s){
    if (s.length()==3)
    {
        cout<<s<<endl;
        return;
    }
    print(s+'0');
    print(s+'1');

    
}
void preorderTraversal(Node *r){
    Node *root = r;
    if (!root)
    {
        return;
    }
    stack<Node*>s;
    s.push(root);
    while (!s.empty())

    {
        Node *current = s.top();
        s.pop();
        cout<<current->data<<" ";
        if (current->right!=NULL)
        {
            s.push(current->right);
        }
        if (current->left!=NULL)
        {
            s.push(current->left);
        }
        
    }

    
    
}
void levelOrderTraversal(Node *root){
    if (!root)
    {
        return;
    }
    queue <Node*> q;
    vector<vector<int>> v;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int size= q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            temp.push_back(curr->data);
        }
        v.push_back(temp);
        
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;
    
    
    
    
}
void preorderRec(Node *root){
    if (!root)
    {
        return;
    }
    cout<<root->data<<" ";
    preorderRec(root->left);
    preorderRec(root->right);
    
}
Node* createNode(int val){
    Node *newNode = new Node(val);
    return newNode;
}
int main(){
    Node *root = createNode(10);
    root->left = createNode(8);
    root->right= createNode(11);
    root->left->left = createNode(7);
    root->left->left->right = createNode(1);
    root->left->right= createNode(9);
    root->right->left = createNode(12);
    root->right->right = createNode(13);
    root->right->right->left = createNode(15);
    Node *temp = root;
    preorderTraversal(temp);
    cout<<endl;
    temp = root;
    levelOrderTraversal(temp);
 //   print("");
    return 0;
}