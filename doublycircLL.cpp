#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    void insertAtTail(node *&head, int val)
    {
        node *newNode = new node(val);
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
    void insertAtHead(node *&head, int val)
    {
        node *newNode = new node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;

        head->prev = newNode;
        newNode->prev = temp;
        head = newNode;
    }
    void addValue(node *&head, int val)
    {
        if (head == NULL || head->data >= val)
        {
            insertAtHead(head, val);
            return;
        }
        node *previousNode = head;
        node *currentNode = head->next;
        while (currentNode->data < val && currentNode != head)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode->next == head)
        {
            insertAtTail(head, val);
            return;
        }
        // insert in between
        node *newNode = new node(val);
        newNode->next = previousNode->next;
        newNode->prev = previousNode;
        previousNode->next = newNode;
        currentNode->prev = newNode;
    }
    void displayReverse(node *&head)
    {
        if (head == NULL)
        {
            cout << "Linked List empty\n";
            return;
        }
        node *temp = head->prev;
        do
        {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }
    void display(node *&head)
    {
        if (head == NULL)
        {
            cout << "Linked List empty\n";
            return;
        }

        node *curr = head;
        do
        {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
    void deleteNode(node *&head, int val)
    {
        node *curr = head;
        node *previous = NULL;
        if (head->data == val && head->next == head)
        {
            delete head;
            cout << "Linked List is empty\n";
            return;
        }

        if (val == head->data && head->next != head)
        {
            head->next->prev = head->prev;
            head->prev->next = head->next;
            curr = head;
            head = head->next;
            delete curr;
            return;
        }
        do
        {
            previous = curr;
            curr = curr->next;

        } while (curr != head && val != curr->data);
        if (val == curr->data && curr->next == head)
        {
            previous->next = head;
            head->prev = previous;
            delete curr;
            return;
        }
        if (val == curr->data)
        {
            previous->next = curr->next;
            curr->next->prev = previous;
            delete curr;
            return;
        }
        cout << val << " not found in the list\n";
    }
    ~node()
    {
        cout << "Memory freed with the value: " << this->data << endl;
    }
};

int main()
{
    node *list = NULL;
    node *head = list;
    cout << "1. Add\n2. display\n3. Display reverse\n4. Delete\nEnter choice: ";
    int ch;
    cin >> ch;
    while (ch != 0)
    {
        if (ch == 1)
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            head->addValue(head, val);
        }
        else if (ch == 2)
        {
            head->display(head);
        }
        else if (ch == 3)
        {
            head->displayReverse(head);
        }
        else
        {
            cout << "Enter value to delete: ";
            int val;
            cin >> val;
            head->deleteNode(head, val);
        }

        cout << "1. Add\n2. display\n3. Display reverse\n4. Delete\nEnter choice: ";
        cin >> ch;
    }

    return 0;
}