#include <iostream>
#include <string>
#define nl cout << endl
using namespace std;
class circQueue
{
public:
    int *arr;
    int front, rear, size;
    circQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    void enqueue()
    {
        // check if Q is full
        if ((rear == size - 1 && front == 0) || (front == rear + 1 && front!=0))
        {
            cout << "Queue is full";
            nl;
            return;
        }
        int val;
        cout << "Enter value: ";
        cin >> val;
        if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = val;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        
        arr[++rear] = val;
    }
    void dequeue(){
        if ((front==-1 && rear==-1))
        {
            cout<<"Queue is empty";nl;
        }else if (front==0 && 0==rear )
        {
            cout<<"Value dequeued: "<<arr[rear]<<endl;
            cout<<"Queue is now fully emptied";nl;
            front = rear= -1;
        }
        else if (front==size-1)
        {

            cout<<"Value dequeued: "<<arr[front]<<endl;
            front = 0;
        }else
        {
            cout<<"Value dequeued: "<<arr[front]<<endl;
            front++;
        }
        
    }
    void display(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }nl;
        
    }
};
int main()
{
    //perfect code it is(hopefully)
    circQueue q(5);
    int ch;
    cout<<"1. EN\n2. DE\n3.DISPL\nChoice: ";
    cin>>ch;
    while (ch!=4)
    {
        if (ch==1)
        {
            q.enqueue();
        }else if (ch==2)
        {
            q.dequeue();
        }else if (ch==3)
        {
            q.display();
        }
        cout<<"Choice: ";
        cin>>ch;
        
        
    }
    
    return 0;
}