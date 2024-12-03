#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node(int v){
        val = v;
        next = NULL;
    }
    void pushVal(Node *&head,int val){
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        temp->next = newNode;
        
        return;
    }
    void display(Node *head){
        
        if (head==NULL)
        {
            cout<<"stack is empty\n";
            return;
        }
        Node* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->val<< " ";
            temp = temp->next;
        }cout<<endl;
        
    }
    void popVal(Node *&head){
        if (head==NULL)
        {
            cout<<"stack is empty\n";
            return;
        }
        if (head->next==NULL)
        {

            delete head;
            cout<<"Stack is emptied\n";
            return;
        }
        
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next!=NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        
    }
    ~Node(){
        cout<<"Freeing memory of the value: "<<this->val<<endl;
        // delete this;
    }
};

int main(){
    Node *stack = NULL;
    Node *head = stack;
    cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\nChoice: ";
    int c;
    cin>>c;
    while (c!=4)
    {
        if (c==1)
        {
            int v;
            cout<<"Enter value: ";
            cin>>v;
            stack->pushVal(head,v);
            /* code */
            
        }
        else if (c==2)
        {
            stack->popVal(head);
        }else if(c==3){
            stack->display(head);
        }else{
            return 0;
        }
        cout<<"Choice: ";
        cin>>c;    
        
    }
    
}