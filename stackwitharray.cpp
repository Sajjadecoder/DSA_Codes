#include<iostream>
#include<string>
using namespace std;
class Stack{
    int *arr;
    int top;
    int size;
    public:
    Stack(int size){
        this->size = size;
        arr=  new int[size];
        top = -1;
                
    }
    void push(int val){
        if (top == size-1)
        {
            cout<<"Stack is full\n";
            return;
        }
        top++;
        arr[top] = val;
        
    }
    void pop(){
        if (top<0)
        {
            cout<<"Stack is empty,cannot pop\n";
            return ;
        }
        top--;
        
    }
    void display(){
        for (int i = 0; i <= top; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }
    bool isEmpty(){
        if (top==-1)
        {
            return true;
        }return false;
        
    }    
    void peek(){
        if (!(top<0))
        {
            cout<<arr[top]<<endl;
        }else{
            cout<<"Stack is empty\n";
        }
        
    }
};
int main(){
    Stack s(5);
    int ch;
    cout<<"1. Push\n2. Pop\n3. Peek\n4. Display\n Choice: ";
    cin>>ch;
    while (ch!=5)
    {
        if (ch==1)
        {
            int val;
            cout<<"Enter val: ";
            cin>>val;
            s.push(val);
        }else if (ch==2)
        {
            s.pop();
        }else if (ch==3)
        {
            s.peek();
        }
        else if (ch==4)
        {
            s.display();
        }else
        {
            return 0;
        }
        cout<<"Enter choice: ";
        cin>>ch;
    }
}