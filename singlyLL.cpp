#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    void insertAtHead(Node *&head, int newData)
    {
        Node *temp = new Node(newData);
        temp->next = head;
        head = temp;
    }
    void insertAtEnd(Node *&head, int d)
    {
        Node *newNode = new Node(d);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = NULL;
    }
    void insertInMiddle(Node *&head, int newData)
    {

        if (newData < head->data)
        {
            insertAtHead(head, newData);
            return;
        }

        Node *newNode = new Node(newData);
        Node *current = head;
        Node *previous = head;
        while (current->data < newNode->data && current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        if (current->next == NULL)
        {
            insertAtEnd(head, newData);
            return;
        }

        newNode->next = previous->next;
        previous->next = newNode;
    }
    void deleteNode(Node *&head, int d)
    {
        Node *temp = head;
        if (temp->data == d)
        {
            head->next = NULL;
            head = head->next;
            return;
        }
        Node *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            if (temp->data == d)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
        }
    }
    void print(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void edit(Node *&head, int oldVal,int newVal)
    {
        Node *temp = head;
        
        while (temp != NULL)
        {
            if (temp->data == oldVal)
            {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    Node *list = new Node(60);
    Node *head = list;
    int num, choice;
    cout << "1. Insert At Start\n2. Insert At End\n3. Insert in middle(mixture of 1 & 2)\n4. Delete\n5. Edit\n6. Display list\n ";
    cout << "0. Exit\nChoice: ";
    cin >> choice;
    while (choice != 0)
    {
        /* code */
    }

    list->insertAtHead(head, 20);
    list->insertAtHead(head, 10);
    list->insertAtEnd(head, 70);
    list->insertInMiddle(head, 9);
    list->insertInMiddle(head, 75);
    list->print(head);
    list->deleteNode(head, 10);
    list->print(head);

    return 0;
    delete list, head;
}