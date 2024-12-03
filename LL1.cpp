#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
    void insertAtHead(Node *&head,int val){
        Node *newNode = new Node(val);
        if (head==nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        
    }
    void insertAtTail(Node *&head,int val){
        Node *newNode = new Node (val);
        Node *temp = head;
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void InsertAtMiddle(Node *&head,int val){
        if (head==nullptr || val<=head->data)
        {
            insertAtHead(head,val);
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp!=nullptr && val>=temp->data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp==nullptr)
        {
            insertAtTail(head,val);
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp;
        prev->next = newNode;
        
    }
    void display(Node *&head){
        if (head==nullptr)
        {
            cout<<"Empty List\n";
            return;
        }
        Node *temp = head;
        while (temp!=nullptr)
        {
            cout<<temp->data<< " ";
            temp = temp->next;
        }cout<<endl;
        
        
    }
    void deleteNode(Node*& head,int val){
        if (head==nullptr)
        {
            cout<<"Empty List\n";
            return;
        }
        if (head->next==nullptr && head->data == val)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp =head;
        Node *prev = nullptr;
        while (temp!=nullptr && temp->data!=val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp==head)     
        {
            head = head->next;
            delete temp;
            return;
        }
        
        if (temp==nullptr)
        {
            cout<<"Value: " << val<<" Not Found In The List\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        
        
        
    }
    ~Node(){
        cout<<"Memory freed with the value: "<<this->data<<endl;
    }

};
int main(){
    Node *listHead = nullptr;
    cout<<"1. Insert\n";
    cout<<"2. Display\n";
    cout<<"3. Delete\n";
    cout<<"4. Exit\nChoice: ";
    int ch;
    cin>>ch;
    while (ch!=4)
    {
        if (ch==1)
        {
            cout<<"Enter Value: ";
            int val;
            cin>>val;
            listHead->InsertAtMiddle(listHead,val);
        }else if (ch==2)
        {
            listHead->display(listHead);
        }
        else if (ch==3)
        {
            cout<<"Enter Value to Delete: ";
            int val;
            cin>>val;
            listHead->deleteNode(listHead,val);
        }
        
        cout<<"Enter Choice(1,2,3,4): ";
        cin>>ch;
        
        
    }
    delete listHead;
    return 0;
}