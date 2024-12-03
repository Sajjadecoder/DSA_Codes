#include<iostream>
#include<string>
using namespace std;
class Person{
    int age;
    char *name;
    public:
    Person(){}
    Person(int age,string &n):age(age) {
        name = new char[n.size()];
        for (int i = 0; i <n.size(); i++)
        {
            *(name + i) = n[i];
            cout<<name[i];
        }
        cout<<name<<endl;
        
    }
};


int main(){
    string s1 = "Sajjad Ahmed";
    Person p1(10,s1);
    return 0;
}