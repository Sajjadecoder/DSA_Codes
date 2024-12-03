#include <iostream>
#include <string>
#define nl cout << endl
using namespace std;
class MyQueue
{
public:
    int front, rear, size;
    int *arr;
    MyQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void enqueue()
    {
        if (rear == size)
        {
            cout << "Queue is full";
            nl;
            return;
        }
        int val;
        cout << "Enter value: ";
        cin >> val;
        arr[rear++] = val;
    }
    int dequeue()
    {
        if (front == rear)
        {
            
            return -1;
        }
        cout<<"Front: "<<front;nl;
        int val = arr[front];
        front++;
        return val;
    }
    int getSize()
    {
        return (rear - front);
    }
    void display()
    {
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        nl;
    }
};
int main()
{
    int ch;
    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    MyQueue q(size);
    cout << "1. Enqueue";
    nl;
    cout << "2. Dequeue";
    nl;
    cout << "3. Size";
    nl;
    cout << "4. Display";
    nl;
    cout << "5. Exit";
    nl;
    cout << "Enter choice: ";
    cin >> ch;
    while (ch != 5)
    {
        if (ch == 1)
        {
            q.enqueue();
        }
        else if (ch == 2)
        {
            int val = q.dequeue();
            if (val==-1)
            {
                cout<<"Queue is empty";nl;
            }else{

            
            cout << "Value Dequeued: " <<val;
            nl;
            }
        }
        else if (ch == 3)
        {
            cout << "Size is: " << q.getSize();
            nl;
        }
        else if (ch == 4)
        {
            q.display();
        }
        else
        {
            break;
        }
        if (ch != 5)
        {
            cout << "Choice: ";
            cin >> ch;
        }
    }

    return 0;
}