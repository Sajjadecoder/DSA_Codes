#include <iostream>
#include <string>
using namespace std;
class Stack
{
    int n;
    char *arr;
    int top = -1;

public:
    Stack(string str)
    {
        n = str.length();
        arr = new char[n];
    }
    void push(string str)
    {
        int cnt = 0;
        while (cnt != str.length())
        {
            arr[++top] = str[cnt];
            cnt++;
        }
    }
    void pop(){
        if (top<0)
        {
            cout<<"Stack is empty\n";return;
        }
        
        top--;

    }
    void display(){
        int temp = top;
        while (top>=0)
        {
            cout<<arr[top];
            top--;
        }
        top = temp;
        
    }
};

int main()
{
    Stack s("hi");
    s.push("hi");
    s.display();
    return 0;
}