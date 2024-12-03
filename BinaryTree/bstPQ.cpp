#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int age;
    Student() {}
    Student(string n, int a) : name(n), age(a) {}
};
struct Node
{
    Student student;
    Node *left;
    Node *right;
    Node(string n, int a)
    {
        student = Student(n, a);
        left = right = NULL;
    }
};
Node *insertNode(Node *root, string name, int age)
{
    if (!root)
    {
        return new Node(name, age);
    }
    if (root->student.age > age)
    {
        root->left = insertNode(root->left, name, age);
    }
    else
    {

        root->right = insertNode(root->right, name, age);
    }
    return root;
}
void traversal(Node *root)
{
    if (!root)
    {
        return;
    }
    traversal(root->left);
    cout << root->student.name << " " << root->student.age << endl;
    traversal(root->right);
}
int main()
{
    Student arr[7] = {Student("Sajjad", 19),
                      Student("Amir", 11),
                      Student("Ahmer", 13),
                      Student("John", 25),
                      Student("Aslam", 15),
                      Student("Aun", 37),
                      Student("Messi", 21)

    };
    Node *root = NULL;
    for (int i = 0; i < 7; i++)
    {
        root = insertNode(root, arr[i].name, arr[i].age);
    }
    traversal(root);

    return 0;
}