#include <iostream>
#include <string>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
    void addNode(Node *&head, int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        temp->next = newNode;
        return;
    }
    void display(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void removeDup1(Node *&head) // will work only on sorted list
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        Node *curr = head;
        while (curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
                // curr->next->next = NULL;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    void removeDup2(Node *&head)
    {
        Node *curr = head;
        map<int, bool> visited;
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (visited[curr->val] == true)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                visited[curr->val] = true;
                // cout<<visited[curr]<<" ";
                prev = curr;
                curr = curr->next;
            }
        }
    }
};
int main()
{
    Node *list1 = NULL;
    Node *head = list1;
    cout << "1. Add\n2. Remove Duplicate(without map)\n3. Remove Duplicate(with map)\n4. Display\n5. Exit\nEnter choice: ";
    int ch;
    cin >> ch;
    while (ch != 5)
    {
        if (ch == 1)
        {
            int val;
            cout << "Enter val: ";
            cin >> val;
            list1->addNode(head, val);
        }
        else if (ch == 2)
        {
            list1->removeDup1(head);
        }
        else if (ch == 4)
        {
            list1->display(head);
        }
        else if (ch == 3)
        {
            list1->removeDup2(head);
        }

        if (ch != 5)
        {
            cout << "Enter choice: ";
            cin >> ch;
        }
    }

    return 0;
}