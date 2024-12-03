#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    void insertAtHead(Node *&head, int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    void insertAtTail(Node *&head, int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertAtAPositionGiven(Node *&head, int pos, int val)
    {
        Node *temp = head;
        int count = 0;
        if (pos == 0) // pos is the index of insertion
        {
            insertAtHead(head, val);
            return;
        }
        pos--;
        while (count != pos)
        {
            count++;
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertInMiddle(Node *&head, int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }

        Node *temp = head;
        Node *prev = temp;
        if (temp->data >= val)
        {
            insertAtHead(head, val);
            return;
        }
        while (temp->next != NULL && val > temp->data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            insertAtTail(head, val);
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
    }
    void deleteNode(Node *&head, int val)
    {
        Node *temp = head;
        if (temp->data == val)
        {
            head = temp->next;
            temp->next = NULL;
            return; // deleting the first node
        }
        Node *prev = temp;
        temp = temp->next;
        while (temp != NULL && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Value not found in the list\n";
            return;
        }
        prev->next = temp->next;
        temp->next = NULL;
    }
    void update(Node *&head, int val)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                int newVal;
                cout << "Enter new value: ";
                cin >> newVal;
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        }
        cout << val << " doesn't exists in the list\n";
    }
    void reverse(Node *&head)
    {
        Node *prev = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        head = prev;
    }
};
int main()
{
    // singly LL
    Node *list1 = NULL;

    Node *head = list1;
    cout << "1. Add\n2. Remove\n3. Update\n4. Reverse\n5. Display\n6. Exit\nEnter Choice: ";
    int ch;
    cin >> ch;
    while (ch != 6)
    {
        int val;
        switch (ch)
        {
        case 1:
            cout << "Enter value to be added: ";
            cin >> val;
            list1->insertInMiddle(head, val);
            break;

        case 2:
            // int val;
            cout << "Enter value to be deleted: ";
            cin >> val;
            list1->deleteNode(head, val);
            break;

        case 3:
            // int val;
            cout << "Enter value to be updated: ";
            cin >> val;
            list1->update(head, val);
            break;
        case 4:
            list1->reverse(head);
            break;
        case 5:
            // cout<<"c";
            list1->display(head);
            break;
        case 6:
            cout << "Exiting";
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
        if (ch != 6)
        {
            cout << "Enter Choice: ";
            cin >> ch;
        }
    }
}