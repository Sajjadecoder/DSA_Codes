#include<iostream>
#include<string>
#include<queue>
#define nl cout<<endl
using namespace std;
int main(){
    queue <int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    cout<<"Size of Q: "<<q.size();nl;
    cout<<"Front of Q: "<<q.front();
    return 0;
}