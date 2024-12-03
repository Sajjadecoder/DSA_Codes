#include<iostream>
#include<string>
using namespace std;
class cirQueue{
    int front,rear,n;
    int *arr;
    public:
    cirQueue(int n){
        this->n = n;
        front = rear = 0;
        arr = new int[n]{0};
    }
    bool isFull(){
        return (front==rear && arr[front]!=0);
    }
    void enqueue(int val){
        if (isFull())
        {
            cout<<"Queue full\n";
            return;
        }
        rear = (rear+1)%n;
        arr[rear] = val;
        
    }
    bool isempty(){
        return (rear==front && arr[front]==0);
    }
    int dequeue(){
        int x=0;
        if (isempty())
        {
            cout<<"Queue empty\n";
            return -1;
        }
        
        front = (front+1)%n;
        x = arr[front];
        arr[front] = 0;
        return x;
        
    }
    void print(){
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }
};

int main(){
    cirQueue q(7);
    cout<<"1. Enqueue\n2. Dequeue\n3. Exit: ";
    cout<<"\nEnter choice: ";
    int count = 0;
    int ch;
    cin>>ch;
    while (ch!=3)
    {
        if (ch==1)
        {
            count+=10;
            q.enqueue(count);
            q.print();
        }
        if (ch==2)
        {
            int x = q.dequeue();
            if (x!=-1)
            {
                cout<<"Value dequeued: "<<x<<endl;
            }
                q.print();
            
        }
        if (ch!=3)
        {
            cout<<"Enter choice: ";
            cin>>ch;
        }
        
        
    }
    
    return 0;
}