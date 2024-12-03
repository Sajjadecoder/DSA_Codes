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
    void insertAtTail(Node *&head, int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    void insertAtHead(Node *&head, int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void addNode(Node *&head, int val)
    {
        if (head == NULL) // if list is empty
        {
            head = new Node(val);
            head->next = head;
            // cout << "Head: " << head->data << endl;
            return;
        }
        Node *temp = head;
        if (val <= temp->data) // insert at beginning
        {
            insertAtHead(head, val);
            return;
        }
        Node *prev = NULL;
        while (temp->next != head && temp->data < val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == head)
        {
            insertAtTail(head, val);
            return;
        }
        else
        {
            Node *newnode = new Node(val);
            newnode->next = prev->next;
            prev->next = newnode;
        }
    }

    void display(Node *&head)
    {
        if (head == nullptr)
            return; // If the list is empty, just return

        Node *temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
    void deleteNode(Node *&head, int val)
    {
        if (head->data == val && head->next == head)
        {
            head->next = NULL;
            delete head;
            return;
        }
        if (head->data == val)
        {
            Node *prevHead = head;
            head = head->next;
            Node *temp = head;
            while (temp->next != prevHead)
            {
                temp = temp->next;
            }
            temp->next = head;
            return;
        }

        Node *prevNode = head;
        Node *temp = head->next;

        while (temp != head)
        {
            if (temp->data == val)
            {
                prevNode->next = temp->next;
                temp->next = NULL;
                temp = prevNode->next;
                return;
            }
            else
            {
                prevNode = temp;
                temp = temp->next;
            }
        }
    }
    void edit(Node *&head, int val)
    {

        cout << "Enter new number: ";
        int num;
        cin >> num;
        Node *temp = head;
        if (head->data == val)
        {
            head->data = num;
            return;
        }
        temp = temp->next;
        while (temp != head)
        {
            if (temp->data == val)
            {
                temp->data = num;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "Number not found\n";
    }
};
int main()
{
    Node *list = NULL;
    Node *head = list;
    cout << "1. Add a node\n2. Delete a node\n3. Edit a node\n4. Display all nodes\n5. Exit\nEnter Choice: ";
    int ch;
    cin >> ch;
    while (ch != 5)
    {

        switch (ch)
        {
        case 1:
            cout << "Enter number to add: ";
            int num;
            cin >> num;
            list->addNode(head, num);
            break;

        case 2:
            cout << "Enter number to delete: ";

            cin >> num;
            list->deleteNode(head, num);
            break;

        case 3:
            cout << "Enter number to edit: ";

            cin >> num;
            list->edit(head, num);
            break;

        case 4:
            list->display(head);
            break;

        case 5:
            break;

        default:
            cout << "Invalid choice\nRe-Enter: ";
            cin >> ch;
            break;
        }
        if (ch != 5)
        {
            cout << "Enter Choice: ";
            cin >> ch;
        }
    }
    return 0;
}