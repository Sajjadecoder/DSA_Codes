#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
    void display(Node *head)
    {
        Node *temp = head;
        // cout << "Printing from start to end:\n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getLength(Node *head)
    {
        Node *temp = head;
        int len = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    void insertAtHead(Node *&head, int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;

        head->prev = newNode;
        head = newNode;
    }
    void insertAtMiddle(Node *&head, int val)
    {
        Node *temp = head;
        Node *pre = temp;
        if (temp->data >= val)
        {
            insertAtHead(head, val);
            return;
        }
        temp = temp->next;
        while (temp->next != NULL && temp->data < val)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp->next == NULL && temp->data <= val)
        {
            insertAtTail(head, val);
            return;
        }
        cout << "Pre: " << pre->data << endl; // printing to check values
        cout << "Temp: " << temp->data << endl;
        Node *newNode = new Node(val);
        newNode->next = pre->next;
        temp->prev = newNode;
        pre->next = newNode;
        newNode->prev = pre;
    }
    void deleteNode(Node *&head, int val)
    {
        while (head != NULL && head->data == val)
        {
            Node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
        }

        // Now head is guaranteed to be non-NULL and head->data != val, or head is NULL
        Node *temp = head;
        Node *prevNode = NULL;
    
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                if (prevNode != NULL)
                {
                    prevNode->next = temp->next;
                    if (temp->next != NULL)
                    {
                        temp->next->prev = prevNode;
                    }
                }
                Node *nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            }
            else
            {
                prevNode = temp;
                temp = temp->next;
            }
        }
    }
    void insertAtTail(Node *&head, int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
        // delete temp; ye line likhne se errors arhe
    }
};
int main()
{
    Node *List = new Node(10);
    Node *head = List;
    List->insertAtHead(head, 7);
    List->display(head);
    List->insertAtTail(head, 20);
    List->display(head);
    List->insertAtMiddle(head, 15);
    List->display(head);
    List->insertAtMiddle(head, 25);
    List->display(head);
    List->deleteNode(head, 15);
    List->display(head);
    return 0;
}